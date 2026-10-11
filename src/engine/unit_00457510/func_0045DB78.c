#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0045DB78_arg0 {
    char pad0[0x38C];
    f32 unk38C;
    char pad390[0x10];
    f32 unk3A0;
    char pad3A4[0x5C];
    s32 unk400;
    f32 unk404;
    char pad408[0x3C];
    s32 unk444;
};

void func_0045DB78(struct func_0045DB78_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;

    if (arg0->unk400 != 0) {
        temp_f0 = arg0->unk38C;
        if ((((arg0->unk3A0 - temp_f0) * arg0->unk404) + temp_f0) < fparg0) {
            arg0->unk444 = 1;
        }
    }
}
