#ifndef MAIN_H
#define MAIN_H

#include "xc.h"
#include "p32xxxx.h"
#include <pic32m_builtins.h>

void uart_init(void);
void uart_putstr(const char* csz_string);

void delay_us(unsigned int us);
void delay_ms(int ms);

#endif