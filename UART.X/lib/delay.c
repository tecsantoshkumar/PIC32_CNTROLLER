/* 
 * File:   delay.c
 * Author: tec Santosh Kumar
 *
 * Created on 20 April, 2022, 11:44 AM
 */

#include <pic32m_builtins.h>
#include "xc.h"
#include "p32xxxx.h"

#define SYS_FREQ        10000

void delay_us(unsigned int us) {
    us *= SYS_FREQ / 4; // Core Timer updates every 2 ticks
    _CP0_SET_COUNT(0);
    while (us > _CP0_GET_COUNT());
}
void delay_ms(int ms) {
    delay_us(ms * 1000);
}