#include "kernel.h"

void kernel_main() {
    terminal_initialize();
    terminal_write("MyOS kernel started\n");

    memory_init();
    scheduler_init();

    while (1) {
        scheduler_run();
    }
}
