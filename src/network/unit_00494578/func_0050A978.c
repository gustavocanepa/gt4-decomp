#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 memcpy(s32, s32, s32);       /* extern */

extern char D_00853568[];
void func_0050A978(s32 arg0) {
    memcpy((s32)D_00853568, arg0, 0x18);
}
