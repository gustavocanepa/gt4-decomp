#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0042D9F0(void *);
void func_0042DC00(s32, f32);
void func_0042DAA0(s8 *arg0, f32 fparg0) {
    s8 *p = arg0;
    p += func_0042D9F0(arg0) * 4;
    func_0042DC00(*(s32 *)(p + 0xC), fparg0);
}
