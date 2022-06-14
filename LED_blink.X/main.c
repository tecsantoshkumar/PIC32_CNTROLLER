#include "xc.h"
#include "p32xxxx.h"
#include <pic32m_builtins.h>

void delay() {
    int i;
    for (i = 0; i < 1000000; i += 1);
}

int main() {
    
    TRISBbits.TRISB14 = 0; // RB3 is output 

    while (1) {
        delay();
        LATBbits.LATB14 = 0;
        delay();
        LATBbits.LATB14 = 1;
    }
    return 0;
}