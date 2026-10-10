#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00397C38_arg0 {
    char pad0[0xEA0];
    f32 unkEA0;
    char padEA4[0x8FC];
    f32 unk17A0;
    char pad17A4[0x10];
    f32 unk17B4;
    f32 unk17B8;
    f32 unk17BC;
    f32 unk17C0;
    f32 unk17C4;
    f32 unk17C8;
};

void func_00397C38(struct func_00397C38_arg0 *arg0) {
    if ((arg0->unk17B4 == 0x0.0p+0f) && (arg0->unk17B8 == 0x0.0p+0f) && (arg0->unk17BC == 0x0.0p+0f) && (arg0->unk17C0 == 0x0.0p+0f)) {
        arg0->unk17B4 = 0x1.0000000000000p+0f;
        arg0->unk17B8 = 0x1.0000000000000p+0f;
        arg0->unk17BC = 0x1.0000000000000p+0f;
        arg0->unk17C0 = 0x1.0000000000000p+0f;
        arg0->unk17C4 = 0x1.0000000000000p+0f;
        arg0->unk17C8 = 0x1.0000000000000p+0f;
    }
    if (arg0->unk17A0 == 0x0.0p+0f) {
        arg0->unk17A0 = 0x1.0000000000000p+0f;
    }
    arg0->unkEA0 = 0x1.0000000000000p+0f;
}
