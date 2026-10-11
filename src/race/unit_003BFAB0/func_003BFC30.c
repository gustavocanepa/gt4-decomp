#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceEventQueue__structor_1(void *, s32);             /* extern */
s32 func_003BFD90();                            /* extern */
s32 func_003BFE10(void *);                      /* extern */
s32 func_003BFF38(void *);                      /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00681AB8[];
struct func_003BFC30_arg0 {
    char pad0[0x974];
    s32 unk974;
};

void func_003BFC30(void *arg0, s32 arg1) {
    ((struct func_003BFC30_arg0 *)arg0)->unk974 = (s32)D_00681AB8;
    func_003BFD90();
    func_003BFE10(arg0);
    func_003BFF38(arg0);
    RaceEventQueue__structor_1(arg0 + 0xF4, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
