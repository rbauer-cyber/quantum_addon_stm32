/*
 * QFsys.h
 *
 *  Created on: May 12, 2025
 *      Author: rbauer
 */

#ifndef INC_QFSYS_H_
#define INC_QFSYS_H_

#ifdef __cplusplus
extern "C" {
#endif

void QF_int_disable_(void);
void QF_int_enable_(void);
void QF_crit_entry_(void);
void QF_crit_exit_(void);

volatile void QF_setSysAppEvent();
volatile void QF_clearSysAppEvent();
volatile uint16_t QF_getSysAppEvent();

#ifdef __cplusplus
}
#endif

#endif /* INC_QFSYS_H_ */
