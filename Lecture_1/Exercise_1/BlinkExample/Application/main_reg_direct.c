/**
  * @brief This is runtime counter
  */
static volatile uint32_t runtime = 0;

/**
  * @brief  This function inits the GPIO pin which connected to board led
  *
  * @retval None
  */
void gpio_init(void)
{
  //uint32_t rcc_base   = 0x40021000
  //uint32_t gpioe_base = 0x48001000
  
  /* Enable GPIOE clock */
  *(uint32_t *)0x40021014 |= 0x00200000; // RCC->AHBENR = 0x00200000;

  /* Set output mode */
  /* Out mode  = 0b01 */
  *(uint32_t *)0x48001000 = 0x55550000; //GPIOE->MODER = 0x55550000;
}

/**
  * @brief  This function init timer to updates each 1 millisecond
  *         and set up interrupt to handle it
  * 
  * @retbal None
  */
void timer_init(void)
{
  //uint32_t tim4_base = 0x40000800;
  //uint32_t nvic_base = 0xE000E100;

  /* Enable TIM4 clock */
  *(uint32_t *)0x4002101C |= 0x00000004; // RCC->APB1ENR |= 0x00000004;

  /* Set period 8000 */
  *(uint32_t *)0x4000082C = 8000; // TIM4->ARR = 8000;
  
  /* Set Interrupt priority */
  *(uint32_t *)0xE000E41E |= /*TBD*/     // NVIC->IP[30] = ???
  
  /* Enable Interrupt 30 (TIM4)*/
  *(uint32_t *)0xE000E100 |= 0x40000000; // NVIC->ISER[0] |= 0x40000000; 

  /* Enable TIM4 update interrupt */
  *(uint16_t *)0x4000080C |= 0x0001; // TIM4->DIER |= 0x0001;

  /* TIM4 enable */
  *(uint32_t *)0x40000800 |= 0x00000001; // TIM4->CR1 |= 0x00000001;
}

/**
  * @brief This function set up system clock source as High Speed Internal (HSI) source
  * 
  * @retval
  */
void clk_init(void)
{
  /* Enable HSI */
  //(uint32_t *)0x40021000 |= 0x00000001; // RCC->CR |= 0x00000001;

  //while(*(uint32_t *)0x40021000 & 0x00000002 == 0)
  //{
    /* Wait while HSI source is not ready */
  //}

  /* Switch to HSI */
  //(uint32_t *)0x40021004 &= 0xFFFFFFFC; // RCC->CFGR &= 0xFFFFFFFC;
}

/**
  * @brief This function perform a delay in miliseconds
  * 
  * @retval None
  */
void delay_ms(uint32_t delay)
{
  uint32_t target_runtime = runtime + delay;

  while(target_runtime != runtime)
    {
      /* Wait while runtime variable reach target_runtime value */
    }
}

/**
  * @brief  This is Main routine. 
  *         It is init all necessary perephery and then just toggle LED with 1 sec period.
  * 
  * @retval If main routine return you something, then you get in trouble :)
  */
int main(void)
{
  clk_init();
  timer_init();
  gpio_init();
  
  while(1)
  {
    /* Switch on LEDs */
    *(uint32_t *)0x48001018 = 0x0000FF00; // GPIOE->BSRR = 0x0000FF00;
    delay_ms(500);
    /* Switch off LEDs */
    *(uint32_t *)0x48001018 = 0xFF000000; // GPIOE->BSRR = 0xFF000000;
    delay_ms(500);
  }

  return 0;
}

/**
  * @brief  This is an interrupt handler routine for TIM4.
  *         It just check if source of interrupt is Timer Update event.
  *         If yes, then it updates runtime counter and clear pending bit.
  *
  * @retval None
  */
void TIM4_IRQHandler(void)
{
  if(*(uint16_t *)0x40000810 & 0x0001 == 1)
  {
    runtime++;
    /* Clear interrupt flag */
    *(uint16_t *)0x40000810 &= 0xFFFE; // TIM4->SR &= 0xFFFE; 
  } 
}

