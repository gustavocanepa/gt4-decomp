#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00575DA0(s32);
void func_003FF9A0(s32 *arg0) {
    if (arg0[2] != 0) {
        func_00575DA0(arg0[2]);
        arg0[2] = 0;
    }
    if (arg0[4] != 0) {
        func_00575DA0(arg0[4]);
        arg0[4] = 0;
    }
    arg0[1] = 0;
    arg0[3] = 0;
    arg0[0] = 0;
}
