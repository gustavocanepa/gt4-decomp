#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00439220(s32, s32);                    /* extern */

extern char D_006A5958[];
extern char D_006A61E8[];
extern char D_006A5928[];
s32 func_00436D20(s32 arg0) {
    if (func_00439220(arg0 + 0x24, (s32)D_006A61E8) != 0) {
        return (s32)D_006A5958;
    }
    return (s32)D_006A5928;
}
