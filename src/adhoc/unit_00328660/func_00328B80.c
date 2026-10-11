#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00328B80_arg1 {
    u8 pad0[0x4];
    s32 unk4;
    s32 unk8;
};
struct func_00328B80_arg0 {
    u8 pad0[0x38];
    s32 unk38;
    s32 unk3C;
    u8 pad40[0x4];
    s32 unk44;
};

void func_00328B80(struct func_00328B80_arg0 *arg0, struct func_00328B80_arg1 *arg1) {
    s32 temp_v0;

    arg1->unk4 = 0;
    arg1->unk8 = 0;
    temp_v0 = arg0->unk38;
    if (temp_v0 != 0) {
        free(temp_v0);
    }
    arg0->unk38 = (s32) arg1;
    arg0->unk3C = (s32) (arg0->unk3C - arg0->unk44);
}
