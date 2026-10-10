#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005B0870_arg1 {
    char pad0[0x8];
    s32 unk8;
};
struct func_005B0870_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_005B0870(struct func_005B0870_arg0 *arg0, struct func_005B0870_arg1 *arg1) {
    arg1->unk8 = (s32) arg0->unk10;
}
