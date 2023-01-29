#ifndef DRIVERS_DS3231_H_
#define DRIVERS_DS3231_H_

#include "i2c.h"

#ifdef __cplusplus
 extern "C" {
#endif

typedef enum {
	DS3231_DAY_SUN = 1,
	DS3231_DAY_MON,
	DS3231_DAY_TUE,
	DS3231_DAY_WED,
	DS3231_DAY_THU,
	DS3231_DAY_FRI,
	DS3231_DAY_SAT,
}ds3231_day_t;

typedef struct {
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	uint8_t day;
	uint8_t date;
	uint8_t month;
	uint8_t year;
}ds3231_time_t;

/* used i2c driver */
extern i2cdrv_t* ds3231i2cdrv;

void ds3231_register_driver(i2cdrv_t* drv);
bool ds3231_get_time(ds3231_time_t *info);
void ds3231_print_time(ds3231_time_t *info);
char* ds3231_day_to_string(ds3231_day_t day);

#ifdef __cplusplus
}
#endif

#endif /* DRIVERS_DS3231_H_ */
