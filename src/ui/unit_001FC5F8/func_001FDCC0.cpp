#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_001055C0();                            /* extern */
s32 func_00107B98(void *);                      /* extern */
s32 func_004A4550(s32, s32);            /* extern */

struct func_001FDCC0_arg0 {
    char pad0[0x80];
    s32 unk80;
    char pad84[0x30];
    s32 unkB4;
};

void func_001FDCC0(char *arg0) {
    if ((((struct func_001FDCC0_arg0 *)arg0)->unkB4 != 0) && (((struct func_001FDCC0_arg0 *)arg0)->unk80 == 1)) {
        func_001055C0();
        func_00107B98(arg0 + 0x40);
        ((struct func_001FDCC0_arg0 *)arg0)->unk80 = 0;
        func_004A4550(2, 1);
        func_004A4550(3, 1);
    }
}

}
