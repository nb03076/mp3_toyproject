#ifndef CLOCK_H_
#define CLOCK_H_

#ifdef __cplusplus
 extern "C" {
#endif

void hal_bus_init_early(void);
void hal_clock_deinit_early(void);

void hal_clock_init_early(void);
void hal_ltdc_clock_init_early(void);

void hal_dwt_init_early(void);

#ifdef __cplusplus
}
#endif

#endif /* CLOCK_H_ */
