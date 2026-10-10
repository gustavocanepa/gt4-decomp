#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00490890_arg0 {
    char pad0[0x30];
    f32 unk30;
    f32 unk34;
    char pad38[0x14];
    s32 unk4C;
};

void func_00490890(struct func_00490890_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk30 = fparg0;
    arg0->unk34 = fparg1;
    arg0->unk4C = 0;
}
