#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0035C7C8(void *);
void func_0035D108(s8 *arg0, s32 arg1) {
    if (func_0035C7C8(arg0) != 0) {
        s8 *p = arg0 + 0x788;
        if (arg1 != 0) {
            *p = 0x22;
            return;
        }
        *p = 0;
    }
}
