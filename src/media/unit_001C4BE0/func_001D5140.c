#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void UnloadSphereMapperModel(void *);
void free(s32);
void func_001D5140(s32 *arg0) {
    UnloadSphereMapperModel(arg0);
    free(arg0[0]);
    free(arg0[1]);
    free(arg0[2]);
    free(arg0[3]);
    free(arg0[4]);
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    arg0[4] = 0;
}
