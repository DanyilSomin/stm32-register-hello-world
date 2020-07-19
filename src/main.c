#include "stm32f10x.h"
#include "light-control/lightcontrol.h"

int main()
{
  	// enable GPIOC port
  	RCC -> APB2ENR |= RCC_APB2ENR_IOPCEN;
  	// --- GPIO setup ----
  	GPIOC->CRH &= ~(uint32_t)(0xf<<20);
  	GPIOC->CRH |=  (uint32_t)(0x2<<20);

	controlLight();

  	return 0;
}