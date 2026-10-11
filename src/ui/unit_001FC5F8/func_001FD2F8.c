#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00105280(s32, s32);                /* extern */
s32 func_00107B00(s32, s32);                /* extern */
s32 func_001FD418();                            /* extern */
s32 Ipic__structor_1(s32, s32);                /* extern */
s32 func_005C1628(s32);                         /* extern */

void func_001FD2F8(s32 arg0, s32 arg1) {
    func_001FD418();
    Ipic__structor_1(arg0 + 0xB8, 2);
    func_00107B00(arg0 + 0x40, 2);
    func_00105280(arg0, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
