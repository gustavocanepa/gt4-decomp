#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00430750_arg0 {
    s64 unk0;
    s8 unk8;
    char pad9[0x3F];
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    char pad54[0x8];
    s32 unk5C;
    s32 unk60;
};

s32 func_00430750(struct func_00430750_arg0 *arg0) {
    arg0->unk0 = -1;
    arg0->unk8 = 0;
    arg0->unk48 = 0;
    arg0->unk4C = 0;
    arg0->unk50 = 0;
    func_00430850((s32) arg0, 1);
    arg0->unk5C = 0;
    arg0->unk60 = -1;
}
