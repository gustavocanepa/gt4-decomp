#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0053EE80(s32);                         /* extern */

struct func_005293A8_arg0 {
    char pad0[0x8];
    s32 unk8;
};

s32 func_005293A8(struct func_005293A8_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 0xD2F2;
    if (arg0 != NULL) {
        func_0053EE80(arg0->unk8);
        var_v0 = 0;
    }
    return var_v0;
}
