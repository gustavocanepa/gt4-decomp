#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00325860(s32);                     /* extern */
s32 func_003266E8();                            /* extern */
s32 func_003267D8(s32, s32);                /* extern */

extern char D_0061A100[];
extern char D_0061A148[];
void func_00327928(s32 arg0) {
    func_00325860((s32)D_0061A148);
    func_003267D8((s32)D_0061A100, arg0);
    func_003266E8();
}
