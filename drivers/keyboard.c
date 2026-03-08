#include "kernel.h"
#include <stdint.h>

uint8_t keyboard_read(){
    uint8_t scancode;
    asm volatile("inb $0x60, %0":"=a"(scancode));
    return scancode;
}

void keyboard_poll(){
    uint8_t key = keyboard_read();
    if(key)
        terminal_putchar('*');
}
