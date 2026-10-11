#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_003E7538(void *);
s32 func_00575E60(s32, s32);
struct func_003E7498_arg0 {
    s32 unk0;
    char pad4[0x30];
    s32 unk34;
    char pad38[0x4];
    f32 unk3C;
    f32 unk40;
};

void func_003E7498(struct func_003E7498_arg0 *arg0) {
    s32 temp_v0;
    temp_v0 = func_00575E60(0x40, 0x4000);
    arg0->unk34 = 0;
    arg0->unk0 = temp_v0;
    arg0->unk3C = 1.0f;
    arg0->unk40 = 1.0f;
    func_003E7538(arg0);
}
