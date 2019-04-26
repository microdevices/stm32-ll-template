#include "main.h"
#include "gpio.h"
#include "rcc.h"
#include "timers.h"


int main(void)
{
	setupSystemClock();
	setupGpio();
	setupTim17();

	loop {
//		LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_6);
		LL_mDelay(200);
	}
}

/**
 * IRQ Handler defined in asm file
 */
void TIM17_IRQHandler(void)
{
	if (LL_TIM_IsActiveFlag_UPDATE(TIM17)) {
		LL_TIM_ClearFlag_UPDATE(TIM17);

		LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_6);
	}
}

/**
  * Error occurrence
  */
void Error_Handler(void)
{
}
