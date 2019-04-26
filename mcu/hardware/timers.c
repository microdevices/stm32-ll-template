#include "timers.h"

/* TIM17 init function */
void setupTim17(void)
{
	LL_TIM_InitTypeDef TIM_InitStruct = {0};

	/* Peripheral clock enable */
	LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_TIM17);

	/* TIM17 interrupt Init */
	NVIC_SetPriority(TIM17_IRQn, 0);
	NVIC_EnableIRQ(TIM17_IRQn);

	TIM_InitStruct.Prescaler = 48;
	TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
	TIM_InitStruct.Autoreload = 10000000U - 1;
	TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
	TIM_InitStruct.RepetitionCounter = 0;
	LL_TIM_Init(TIM17, &TIM_InitStruct);
	LL_TIM_DisableARRPreload(TIM17);

	LL_TIM_EnableCounter(TIM17);
	LL_TIM_EnableIT_UPDATE(TIM17);
}
