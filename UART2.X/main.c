#include "xc.h"
#include "p32xxxx.h"
#include <pic32m_builtins.h>
#include "lib/uart.h"
#include "lib/main.h"


void uart_init(void) {

    U2BRG = (_XTAL_FREQ / (16 * UART_BAUD)) - 1; // ((Fosc/4)/(16 * Baud rate)) - 1

    U2STAbits.URXISEL = 0; // Interrupt flag bit is set for every character received.
    IPC10bits.U2RXIP = 5; // UART2 Receive Interrupt Priority = 4.jn
    U2STAbits.OERR = 0; // Clear the Receive Overflow Flag.
    IFS1bits.U2RXIF = 0; // Clear the UART2 Receive Interrupt flag.
    IEC1bits.U2RXIE = 0; // Disable UART2 Receive Interrupt.
    U2MODEbits.UARTEN = 1; // Enable UART2.
    U2STAbits.UTXEN = 1;
    
    RPOR3bits.RP13R = 1;
    RPINR9bits.U2RXR = 2;

    TRISAbits.TRISA0 = 1; // RB4 is 
    TRISAbits.TRISA1 = 0; // RA4 is output

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

int main() {
    uart_init();
//    TRISBbits.TRISB14 = 0; // RB13 is output 

    while (1) {
        uart_putstr("Santosh");
//        delay_ms(1000);
//        LATBbits.LATB14 = 0;
//        delay_ms(3000);
//        LATBbits.LATB14 = 1;
    }
    return 0;
}