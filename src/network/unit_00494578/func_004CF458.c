#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_004CF458_arg0 {
    char pad0[0x58];
    s32 unk58;
    char pad5C[0xDC];
    s8 unk138;
};

void func_004CF458(struct func_004CF458_arg0 *arg0, s32 arg1) {
    arg0->unk58 = arg1;
    arg0->unk138 = 1;
}
