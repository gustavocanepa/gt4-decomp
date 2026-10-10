#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00600E68_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

void func_00600E68(struct func_00600E68_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unk8;
    arg0->unk8 = arg1;
    arg0->unk4 = temp_v0;
}
