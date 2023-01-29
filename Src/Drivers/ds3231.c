#include "i2c.h"
#include "ds3231.h"
#include "cli.h"
#include <stdbool.h>

#define DS3231_DEV_ADDR 0xD0

#define DS3231_REG_SEC 0x00
#define DS3231_REG_MIN 0x01
#define DS3231_REG_HOUR 0x02
#define DS3231_REG_DAY 0x03
#define DS3231_REG_DATE 0x04
#define DS3231_REG_MONTH 0x05
#define DS3231_REG_YEAR 0x06

#define DS3231_I2C_TIMEOUT 100


i2cdrv_t* ds3231i2cdrv;

static bool ds3231_read_reg(uint8_t reg, uint8_t* data, uint32_t size);

static inline uint8_t B2D(uint8_t bcd);
static inline uint8_t D2B(uint8_t decimal);

void ds3231_register_driver(i2cdrv_t* drv) {
	ds3231i2cdrv = drv;
}

bool ds3231_get_time(ds3231_time_t *info) {
	uint8_t data[7];

	if(ds3231_read_reg(DS3231_REG_SEC, data, 7) != true) {
		hal_cli_printf("ds3231 read register failed");
		return false;
	}

	info->sec = B2D(data[0] & 0x7F);
	info->min = B2D(data[1] & 0x7F);
	info->hour = B2D(data[2] & 0x3F);
	info->day = B2D(data[3] & 0x07);
	info->date = B2D(data[4] & 0x3F);
	info->month = B2D(data[5] & 0x1F);
	info->year = B2D(data[6] & 0xFF);

	return true;
}

void ds3231_print_time(ds3231_time_t *info) {
	hal_cli_printf("hms : %d %d %d",info->hour, info->min, info->sec);
	hal_cli_printf("ymdd : %d %d %d %s", info->year, info->month, info->date, ds3231_day_to_string(info->day));
}

char* ds3231_day_to_string(ds3231_day_t day) {
	switch(day) {
	case DS3231_DAY_SUN:
		return "Sun";
	case DS3231_DAY_MON:
		return "Mon";
	case DS3231_DAY_TUE:
		return "Tue";
	case DS3231_DAY_WED:
		return "Wed";
	case DS3231_DAY_THU:
		return "Thu";
	case DS3231_DAY_FRI:
		return "Fri";
	case DS3231_DAY_SAT:
		return "Sat";
	default:
		hal_cli_printf("ds3231 day to string argument error");
		return 0;
	}
}

static bool ds3231_read_reg(uint8_t reg, uint8_t* data, uint32_t size) {
	return hal_i2c_receive(
			ds3231i2cdrv,
			DS3231_DEV_ADDR,
			reg,
			data,
			size,
			DS3231_I2C_TIMEOUT);
}

static inline uint8_t B2D(uint8_t bcd) {
  return (bcd >> 4) * 10 + (bcd & 0x0F);
}

static inline uint8_t D2B(uint8_t decimal) {
  return (((decimal / 10) << 4) | (decimal % 10));
}
