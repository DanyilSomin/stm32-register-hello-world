#include "lightcontrol.h"

#include "stm32f10x.h"

void  dummy_loop(uint32_t count)
{
    if (count > 0)
    {
        while(--count)
        {

        }
    }
}

void controlLight() 
{
    const int period = 8000;
    const int initSpeed = 1;

    int speed = initSpeed;
    int currDirection = 1;
    int waitOn = 0;

    const int scale = 1;
    int iterationsToSkip = scale;

    while (1)
    {
        if (--iterationsToSkip <= 0)
        {
            iterationsToSkip = scale;

            waitOn += speed * currDirection;
            speed += currDirection;

            if (waitOn < 0) 
            {
                speed = initSpeed;
                waitOn = speed;
                currDirection = 1;
            }
            else if (waitOn > period) 
            {
                waitOn = period - speed;
                currDirection = -1;
            }
        }
        
        GPIOC->BRR=GPIO_BRR_BR13;
        dummy_loop(waitOn);
        GPIOC->BSRR=GPIO_BRR_BR13;
        dummy_loop(period - waitOn);
    }
}
  