#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <atomic>

#include "QFsys.h"

#include "stm32f4xx_hal.h"

#define NO_CRITICAL_SECTIONS

// Define functions for enabling/disabling HAL interrupts for critical sections
// and for setting/detecting Q system events.

#ifdef __cplusplus
extern "C" {
#endif

void QF_int_disable_(void)
{
#ifndef NO_CRITICAL_SECTIONS
	HAL_SuspendTick();
#endif
}

void QF_int_enable_(void)
{
#ifndef NO_CRITICAL_SECTIONS
	//HAL_ResumeTick();
#endif
}

void QF_crit_entry_(void)
{
#ifndef NO_CRITICAL_SECTIONS
	//HAL_SuspendTick();
#endif
}

void QF_crit_exit_(void)
{
#ifndef NO_CRITICAL_SECTIONS
	//HAL_ResumeTick();
#endif
}

// The following set of functions assume the STM32 instructions
// are atomic for reading or writing a 16 bit variables.
// volatile static uint16_t s_sysAppInterrupt = 0;
std::atomic<uint16_t> s_sysAppInterrupt(0);

volatile void QF_setSysAppEvent()
{
	s_sysAppInterrupt.store(1);
}

volatile void QF_clearSysAppEvent()
{
	s_sysAppInterrupt.store(0);
}

volatile uint16_t QF_getSysAppEvent()
{
	return s_sysAppInterrupt.load();
}

#ifdef __cplusplus
}
#endif
