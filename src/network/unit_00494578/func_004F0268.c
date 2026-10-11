#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004EFC88(void *, s32);             /* extern */
s32 func_004F0848();                            /* extern */
s32 func_004F8948(void *, s32);             /* extern */
s32 func_00574DA8(void *, s32);             /* extern */
s32 func_005760A8(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */
s32 func_0060EA20(void *, s32);             /* extern */
s32 func_0060EA70(void *, s32);             /* extern */
s32 func_0060EAC0(void *, s32);             /* extern */

extern char D_00689638[];
struct func_004F0268_arg0 {
    char pad0[0x3FAC];
    s32 unk3FAC;
};

void func_004F0268(void *arg0, s32 arg1) {
    ((struct func_004F0268_arg0 *)arg0)->unk3FAC = (s32)D_00689638;
    func_004F0848();
    func_0060EAC0(arg0 + 0x3BF4, 2);
    func_0060EA70(arg0 + 0x39A4, 2);
    func_004F8948(arg0 + 0xCD8, 2);
    func_0060EA20(arg0 + 0x198, 2);
    func_004EFC88(arg0 + 0x40, 2);
    func_00574DA8(arg0 + 8, 2);
    func_005760A8(arg0, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
