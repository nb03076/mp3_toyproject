#ifndef ADC_H_
#define ADC_H_

#include <stdbool.h>

#ifdef __cplusplus
 extern "C" {
#endif

typedef enum {
 	AdcId1 = 1,
 	AdcId2,
}AdcID;

void adc_init(AdcID id);
bool hal_adc_getdata(AdcID id, uint32_t* data);


#ifdef __cplusplus
}
#endif

#endif /* ADC_H_ */
