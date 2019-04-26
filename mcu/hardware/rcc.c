#include "rcc.h"
#include "main.h"

/**
  * System Clock Configuration
  */
void setupSystemClock(void)
{
	LL_FLASH_SetLatency(LL_FLASH_LATENCY_1);

	if(LL_FLASH_GetLatency() != LL_FLASH_LATENCY_1) {
		Error_Handler();
	}
	LL_RCC_HSI_Enable();

	// Wait till HSI is ready
	while(LL_RCC_HSI_IsReady() != 1);
	LL_RCC_HSI_SetCalibTrimming(16);
	LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSI_DIV_2, LL_RCC_PLL_MUL_12);
	LL_RCC_PLL_Enable();

	// Wait till PLL is ready
	while(LL_RCC_PLL_IsReady() != 1);
	LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
	LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
	LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

	// Wait till System clock is ready
	while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL);
	LL_Init1msTick(48000000);
	LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
	LL_SetSystemCoreClock(48000000);
}
