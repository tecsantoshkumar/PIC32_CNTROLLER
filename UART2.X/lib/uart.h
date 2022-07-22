#ifndef _UART_H
#define _UART_H

// Oscillator Frequency.
#define	_XTAL_FREQ     10000
// Default UART baud rate.
#define UART_BAUD 9.6

void uart_init(void);
unsigned char uart_rec(void);
void uart_trnt(unsigned char uc_data);
void uart_putstr(const char* csz_string);

#endif