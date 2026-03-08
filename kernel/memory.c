#include "kernel.h"

#define HEAP_SIZE 1024*1024

static uint8_t heap[HEAP_SIZE];
static uint32_t heap_index = 0;

void memory_init() {
    heap_index = 0;
}

void* kmalloc(uint32_t size) {
    if(heap_index + size >= HEAP_SIZE)
        return 0;

    void* ptr = &heap[heap_index];
    heap_index += size;
    return ptr;
}
