#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00366CD8_arg0 {
    char pad0[0x78];
    f32 unk78;
    f32 unk7C;
    f32 unk80;
};
struct func_00366CD8_arg1 {
    char pad0[0x20];
    u8 unk20;
    u8 unk21;
    u8 unk22;
};

void func_00366CD8(struct func_00366CD8_arg0 *arg0, struct func_00366CD8_arg1 *arg1) {
    f32 temp_f0;

    arg0->unk78 = (f32) ((f32) arg1->unk20 * 0x1.47ae140000000p-7f);
    temp_f0 = (f32) arg1->unk21 * 0x1.1c71c60000000p-2f;
    arg0->unk7C = (f32) (temp_f0 / 0x1.8ffffe0000000p+5f);
    arg0->unk80 = (f32) (((f32) arg1->unk22 * 0x1.47ae140000000p-7f * 0x1.8ffffe0000000p+5f) / (0x1.bc71c40000000p+4f - temp_f0));
}
