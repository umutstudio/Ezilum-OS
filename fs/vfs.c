#include "kernel.h"

#define MAX_FILES 32

typedef struct {
    char name[32];
    uint8_t data[512];
    int size;
} file_t;

file_t files[MAX_FILES];

void vfs_init(){
    for(int i=0;i<MAX_FILES;i++)
        files[i].size = 0;
}

int vfs_create(const char* name){
    for(int i=0;i<MAX_FILES;i++){
        if(files[i].size==0){
            int j=0;
            while(name[j]){
                files[i].name[j]=name[j];
                j++;
            }
            files[i].size=1;
            return i;
        }
    }
    return -1;
}
