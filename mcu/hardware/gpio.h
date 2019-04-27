#ifndef _GPIO_H
#define _GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f0xx_ll_bus.h"
#include "stm32f0xx_ll_gpio.h"

void setupGpio(void);

#ifdef __cplusplus
}
#endif

#endif // _GPIO_H
