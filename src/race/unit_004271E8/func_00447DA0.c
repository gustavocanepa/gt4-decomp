#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00443E00(s32, s32, s32);           /* extern */

extern char D_006235A8[];
s32 func_00447DA0(s32 arg0) {
    return ~func_00443E00((s32)D_006235A8, arg0, 0x26) != 0;
}
