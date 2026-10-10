#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0025B498(void *, s32, s32);            /* extern */
s32 func_002662A0();                                /* extern */

struct func_0025BF90_arg0 {
    char pad0[0x44];
    s32 unk44;
    s32 unk48;
};

void func_0025BF90(void *arg0) {
    if (func_002662A0() != 0) {
        func_0025B498(arg0, arg0 + 0x44, arg0 + 0x48);
        return;
    }
    ((struct func_0025BF90_arg0 *)arg0)->unk44 = 0;
    ((struct func_0025BF90_arg0 *)arg0)->unk48 = 0;
}
