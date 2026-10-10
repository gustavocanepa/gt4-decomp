#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
void func_004A7890(f32, f32, f32);
struct func_00107328_arg0 {
    char pad0[0x14];
    f32 unk14;
    char pad18[0x8];
    s32 unk20;
};

void func_00107328(struct func_00107328_arg0 *arg0) {
    f32 a = 0.75f;
    if (arg0->unk20 == 0) a = 1.0f;
    func_004A7890(a, arg0->unk14, 1.0f);
}

}
