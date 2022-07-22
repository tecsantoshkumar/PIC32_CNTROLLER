/* 
 * File:   uart.c
 * Author: Tec Santosh Kumar
 *
 * Created on 19 April, 2022, 5:16 PM
 */

//#include "lib/delay.h"
#include "xc.h"
#include "p32xxxx.h"
#include <pic32m_builtins.h>
#include "lib/uart.h"

#pragma config FOSFPR = XT              // Oscillator (XT)
#pragma config FCKSMEN = CSW_FSCM_OFF   // Clock Switching and Monitor (Sw Disabled, Mon Disabled)

void uart_init(void) {

    U2BRG = (_XTAL_FREQ / (16 * UART_BAUD)) - 1; // ((Fosc/4)/(16 * Baud rate)) - 1

    U2STAbits.URXISEL = 0; // Interrupt flag bit is set for every character received.
    IPC10bits.U2RXIP = 5; // UART2 Receive Interrupt Priority = 4.jn
    U2STAbits.OERR = 0; // Clear the Receive Overflow Flag.
    IFS1bits.U2RXIF = 0; // Clear the UART2 Receive Interrupt flag.
    IEC1bits.U2RXIE = 0; // Disable UART2 Receive Interrupt.
    U2MODEbits.UARTEN = 1; // Enable UART2.
    U2STAbits.UTXEN = 1;

    TRISBbits.TRISB14 = 0; // RB4 is 
    TRISBbits.TRISB15 = 1; // RA4 is output

}

void uart_trnt(unsigned char uc_data) {
    while (U2STAbits.UTXBF == 1);
    U2TXREG = uc_data;
}

unsigned char uart_rec(void) {
    while (U2STAbits.URXDA == 0);
    U2STAbits.OERR = 0;
    return U2RXREG;
}

void uart_putstr(const char* csz_string) {
    while (*csz_string != '\0') {
        uart_trnt(*csz_string);
        csz_string++; // Point to next character.
    }
}