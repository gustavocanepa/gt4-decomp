#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00531E28(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 0x17;
    if ((arg1 != 0) && (arg0 != 0)) {
        func_005A6AB0((void *) arg0, arg1 + 0x114, 0x10);
        var_v0 = 0;
    }
    return var_v0;
}
