#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002F3A30(s32, s32);                    /* extern */
s32 func_00305550(s32);                         /* extern */
s32 func_00306780(s32, s32, s32);       /* extern */

extern char D_002F2D78[];
extern char D_0083CE50[];
void func_002F2E80(s32 *arg0, s32 arg1, s32 arg2) {
    func_00305550(*arg0);
    func_002F3A30(*arg0, arg2);
    func_00306780(*arg0, (s32)D_0083CE50, (s32)D_002F2D78);
}
