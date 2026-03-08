 #include <stdint.h>
#include "kernel.h"

volatile uint16_t* video = (uint16_t*)0xB8000;
int cursor_x = 0;
int cursor_y = 0;

void terminal_initialize() {
    for(int y=0;y<25;y++){
        for(int x=0;x<80;x++){
            video[y*80+x] = (uint16_t)' ' | 0x0700;
        }
    }
}

void terminal_putchar(char c) {
    video[cursor_y*80+cursor_x] = (uint16_t)c | 0x0700;
    cursor_x++;
    if(cursor_x>=80){
        cursor_x=0;
        cursor_y++;
    }
}

void terminal_write(const char* str){
    int i=0;
    while(str[i]){
        terminal_putchar(str[i]);
        i++;
    }
}
