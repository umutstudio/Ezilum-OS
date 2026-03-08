#include "kernel.h"

#define MAX_TASKS 16

typedef struct {
    void (*entry)();
    int active;
} task_t;

task_t tasks[MAX_TASKS];

void scheduler_init(){
    for(int i=0;i<MAX_TASKS;i++)
        tasks[i].active=0;
}

void scheduler_add(void (*func)()){
    for(int i=0;i<MAX_TASKS;i++){
        if(!tasks[i].active){
            tasks[i].entry=func;
            tasks[i].active=1;
            return;
        }
    }
}

void scheduler_run(){
    for(int i=0;i<MAX_TASKS;i++){
        if(tasks[i].active)
            tasks[i].entry();
    }
}
