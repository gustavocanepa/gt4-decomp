#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00453488_arg0 {
    char pad0[0x80];
    s32 unk80;
    char pad84[0x538];
    s32 unk5BC;
};

void func_00453488(struct func_00453488_arg0 *arg0, s32 arg1) {
    arg0->unk5BC = arg1;
    arg0->unk80 = (s32) (arg1 != 0);
}
