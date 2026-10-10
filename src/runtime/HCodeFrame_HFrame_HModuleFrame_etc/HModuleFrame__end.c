#include "types.h"
#include "gt4/HModuleFrame.h"
void *func_005A4724(void *, const void *, unsigned int);

struct HModuleFrame__virtual_02_arg1 {
    char pad0[0x20];
    s32 unk20;
};
void HModuleFrame__end(struct HModuleFrame *arg0, struct HModuleFrame__virtual_02_arg1 *arg1) {
    arg1->unk20 = (s32) arg0->unk4;
}
