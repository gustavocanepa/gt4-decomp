#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_0064A280[];
s32 func_00506330(void *arg0, s32 arg1) {
    func_005A6AB0(arg0, (void *)(s32)D_0064A280, arg1);
    M2C_FIELD((arg0 + arg1), s8 *, -1) = 0;
    return 0;
}
