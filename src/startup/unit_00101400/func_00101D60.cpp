#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00101AB0();                            /* extern */
s32 GranTurismo4__BGMPlayList__setDefault(s32, s32);                /* extern */

extern char D_00622F4C[];
void func_00101D60(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_00101AB0();
    GranTurismo4__BGMPlayList__setDefault(*(s32 *)(s32)D_00622F4C + 0x38D40, 0);
    GranTurismo4__BGMPlayList__setDefault(*(s32 *)(s32)D_00622F4C + 0x39550, 0);
}
