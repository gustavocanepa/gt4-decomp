#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00491EB0(void *);
struct func_00490CA0_arg0 {
    char pad0[0x7C];
    s32 unk7C;
};

void func_00490CA0(struct func_00490CA0_arg0 *arg0) {
    if (arg0->unk7C == 0) {
        func_00491EB0(arg0);
        arg0->unk7C = 1;
    }
}
