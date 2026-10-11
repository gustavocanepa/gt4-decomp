#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A0690();                            /* extern */
s32 func_004A06F0();                            /* extern */
s32 func_004A53F8();                            /* extern */
s32 func_004A5400();                            /* extern */
s32 func_004A7454();                            /* extern */
s32 func_004A7550(s32);                         /* extern */

void func_00400EE8(s32 arg0) {
    func_004A0690();
    func_004A53F8();
    func_004A7454();
    func_004A7550(arg0 + 0x100);
    func_004A5400();
    func_004A06F0();
}
