#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00494A28();                            /* extern */

struct func_00494640_arg0 {
    char pad0[0x964];
    s32 unk964;
};

void func_00494640(struct func_00494640_arg0 *arg0, s32 arg1) {
    if (arg0->unk964 != arg1) {
        func_00494A28();
        arg0->unk964 = arg1;
    }
}
