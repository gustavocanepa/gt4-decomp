#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F9E90(s32, s32);                        /* extern */
s32 func_004FA178();                                /* extern */

s32 func_004FB1B0(s32 arg0) {
    return ~func_004F9E90(arg0, func_004FA178()) != 0;
}
