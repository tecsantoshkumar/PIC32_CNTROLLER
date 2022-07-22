#include "lib/delay.h"
#include "xc.h"
#include "p32xxxx.h"
#include <pic32m_builtins.h>
#include "lib/uart.h"
#include "lib/main.h"




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