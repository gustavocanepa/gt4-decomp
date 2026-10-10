#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004470E8();                            /* extern */

struct func_003BB478_arg0 {
    char pad0[0x3E];
    u8 unk3E;
    char pad3F[0x4];
    u8 unk43;
    char pad44[0x45];
    s8 unk89;
    char pad8A[0x26];
    s32 unkB0;
    char padB4[0x5C];
    s64 unk110;
    s32 unk118;
    char pad11C[0xC];
    s32 unk128;
};

void func_003BB478(struct func_003BB478_arg0 *arg0, s64 arg1) {
    u8 temp_v1;

    arg0->unk110 = arg1;
    func_004470E8();
    temp_v1 = arg0->unk3E;
    if (arg0->unk118 >= (s32) temp_v1) {
        arg0->unk118 = (s32) temp_v1;
    }
    arg0->unk128 = (s32) arg0->unk89;
    arg0->unkB0 = (s32) arg0->unk43;
}
