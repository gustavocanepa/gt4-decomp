#define GT4_DECLS
#include "gt4/mWidget.h"
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);


struct func_002B2158_arg0 {
    char pad0[0xB0];
    s32 unkB0;
    char padB4[0x68];
    s32 unk11C;
};

void func_002B2158(struct func_002B2158_arg0 *arg0) {
    s32 temp_a0;

    temp_a0 = arg0->unk11C;
    if (arg0->unkB0 == 0) {
        mWidget__getWindowH(temp_a0);
        return;
    }
    mWidget__getWindowW(temp_a0);
}
