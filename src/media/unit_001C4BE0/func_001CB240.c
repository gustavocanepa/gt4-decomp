#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void free(s32);
void func_001CB240(s32 *arg0) {
    free(arg0[0]);
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    arg0[4] = 0;
}
