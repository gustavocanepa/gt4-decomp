#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00601AB8_arg0 {
    char pad0[0x10DC];
    s32 unk10DC;
};

void func_00601AB8(struct func_00601AB8_arg0 *arg0, s32 arg1) {
    arg0->unk10DC = (s32) (arg1 != 0);
}
