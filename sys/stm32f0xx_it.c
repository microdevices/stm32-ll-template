#include "main.h"
#include "stm32f0xx_it.h"


/**
  * Handle Non maskable interrupt.
  */
void NMI_Handler(void)
{
}

/**
  * Handle Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  while (1)
  {
  }
}

/**
  * Handle System service call via SWI instruction.
  */
void SVC_Handler(void)
{
}

/**
  * Handle Pendable request for system service.
  */
void PendSV_Handler(void)
{
}

/**
  * Handle System tick timer.
  */
void SysTick_Handler(void)
{
}
