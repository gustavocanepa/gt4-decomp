#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_001C1FB0(s32, s32, s32);               /* extern */
s32 func_00574EE8(void *);                      /* extern */
s32 func_00576788(void *);                      /* extern */
s32 func_005767C0(void *);                      /* extern */

struct mGTShirtPS2__virtual_53_arg0 {
    char pad0[0x260];
    s32 unk260;
    s32 unk264;
    char pad268[0x28];
    s32 unk290;
    char pad294[0x80];
    s32 unk314;
};

void mGTShirtPS2__virtual_53(char *arg0, s32 arg1) {
    char *temp_s0;

    if (arg1 == 0) {
        ((struct mGTShirtPS2__virtual_53_arg0 *)arg0)->unk290 = 0;
    } else if (((struct mGTShirtPS2__virtual_53_arg0 *)arg0)->unk314 == 0) {
        temp_s0 = arg0 + 0x2E0;
        func_00576788(temp_s0);
        func_001C1FB0(((struct mGTShirtPS2__virtual_53_arg0 *)arg0)->unk264, arg1, ((struct mGTShirtPS2__virtual_53_arg0 *)arg0)->unk260);
        func_005767C0(temp_s0);
        func_00574EE8(temp_s0);
    }
}

}
