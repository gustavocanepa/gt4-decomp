#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00442A58_arg1 {
    char pad0[0x10A];
    u16 unk10A;
    u8 unk10C;
};
struct func_00442A58_arg2 {
    u16 unk0;
    u16 unk2;
};

void func_00442A58(s32 arg0, struct func_00442A58_arg1 *arg1, struct func_00442A58_arg2 *arg2) {
    arg1->unk10A = (u16) ((s32) (arg1->unk10A * arg2->unk0) / 100);
    arg1->unk10C = (u8) ((s32) (arg1->unk10C * arg2->unk2) / 100);
}
