/*****************************************************************************
 * Copyright (c) 2010, 2011 Rowley Associates Limited.                       *
 *                                                                           *
 * This file may be distributed under the terms of the License Agreement     *
 * provided with this software.                                              *
 *                                                                           *
 * THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE   *
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. *
 *****************************************************************************/

#include <ctl_api.h>
#include <Kinetis.h>

static CTL_ISR_FN_t userTimerISR;

void
SysTick_Handler()
{
  ctl_enter_isr();
  if (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)
    {
      userTimerISR();        
    }
  ctl_exit_isr();
}

int 
ctl_set_isr(unsigned int irq, 
            unsigned int priority,                 
            CTL_ISR_FN_t isr, 
            CTL_ISR_FN_t *oldisr)
{
  if (oldisr)
    *oldisr = *((CTL_ISR_FN_t*)(SCB->VTOR)+16+irq);
  *((CTL_ISR_FN_t*)(SCB->VTOR)+16+irq) = isr;
  NVIC_SetPriority(irq, (1 << (__NVIC_PRIO_BITS - 1)) + priority);
  return 1;
}

void
ctl_set_priority(int irq, int priority)
{
  NVIC_SetPriority(irq, (1 << (__NVIC_PRIO_BITS - 1)) + priority);
}

int
ctl_unmask_isr(unsigned int irq)
{
  NVIC_EnableIRQ(irq);
  return 1;
}

int
ctl_mask_isr(unsigned int irq)
{
  NVIC_DisableIRQ(irq);
  return 1;
}

void ctl_start_timer(CTL_ISR_FN_t timerFn)
{    
  userTimerISR = timerFn;  
  SysTick->LOAD = SystemCoreClock/100; // interrupt every 10 ms
  SysTick->VAL = 0;
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;  
#ifdef CTL_TASKING
  ctl_time_increment = 10; // so increment the counter by 10 to get the ms counter
#endif
  // Set PendSV priority (PendSV must have lowest priority)
  NVIC_SetPriority(PendSV_IRQn, (1 << __NVIC_PRIO_BITS) - 1);
  // Set SysTick priority
  ctl_set_priority(SysTick_IRQn, 0);
}

unsigned long
ctl_get_ticks_per_second(void)
{
#ifdef CTL_TASKING
  return 1000;
#else
  return 100;
#endif
}
