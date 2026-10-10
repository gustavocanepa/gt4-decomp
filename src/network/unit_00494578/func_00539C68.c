#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00539C68_arg0 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    s32 unkC;
    s32 unk10;
};

void func_00539C68(struct func_00539C68_arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk10 = 0;
    arg0->unk0 = arg1;
    arg0->unk8 = arg1;
    arg0->unk4 = arg2;
    arg0->unkC = 0;
    if ((arg1 == 0) || (arg2 == 0) || (arg1 >= arg2)) {
        arg0->unk10 = 2;
    }
}
