#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_002C1718_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_002C1718_temp_v0 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_002C1718_arg0 {
    char pad0[0x28];
    f32 unk28;
    char pad2C[0xC];
    f32 unk38;
};

void func_002C1718(void *arg0, struct func_002C1718_arg1 *arg1, f32 fparg0) {
    struct func_002C1718_temp_v0 *temp_v0;

    temp_v0 = arg0 + 0x28;
    if (temp_v0 != arg1) {
        ((struct func_002C1718_arg0 *)arg0)->unk28 = (f32) arg1->unk0;
        temp_v0->unk4 = (f32) arg1->unk4;
        temp_v0->unk8 = (f32) arg1->unk8;
        temp_v0->unkC = (f32) arg1->unkC;
    }
    ((struct func_002C1718_arg0 *)arg0)->unk38 = fparg0;
}
