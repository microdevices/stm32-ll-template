#ifndef RCC_H_
#define RCC_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f0xx_ll_cortex.h"
#include "stm32f0xx_ll_rcc.h"
#include "stm32f0xx_ll_system.h"
#include "stm32f0xx_ll_utils.h"

void setupSystemClock(void);

#ifdef __cplusplus
}
#endif

#endif // RCC_H_
