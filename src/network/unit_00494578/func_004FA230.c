#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004F9A58(s32, s32);
s32 func_004FA230(s32 arg0, s32 arg1) {
    s32 var_v0;

    if ((arg1 == 0) || (var_v0 = func_004F9A58(arg0, 0), (var_v0 != 0))) {
        var_v0 = func_004F9A58(arg0, 1) != 0;
    }
    return var_v0;
}
