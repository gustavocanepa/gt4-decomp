#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00105500_arg0 {
    char pad0[0x20];
    f32 unk20;
    f32 unk24;
};

void func_00105500(struct func_00105500_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk20 = fparg0;
    arg0->unk24 = fparg1;
}
