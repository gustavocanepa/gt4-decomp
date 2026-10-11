#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004EB798_arg0 {
    char pad0[0x18];
    s32 (*unk18)(s32, s32);
    s32 unk1C;
    char pad20[0x28];
    s32 unk48;
};

void func_004EB798(struct func_004EB798_arg0 *arg0) {
    s32 (*temp_v1)(s32, s32);

    temp_v1 = arg0->unk18;
    if (temp_v1 != NULL) {
        temp_v1(arg0->unk48 == 0, arg0->unk1C);
    }
}
