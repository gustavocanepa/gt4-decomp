#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005786A8_arg0 {
    char pad0[0x44];
    s32 unk44;
    s32 unk48;
};

s32 func_005786A8(s32 arg0, s32 arg1) {
    s32 var_s0;

    var_s0 = 0;
    if (((struct func_005786A8_arg0 *)arg0)->unk44 != 0) {
        var_s0 = ((struct func_005786A8_arg0 *)arg0)->unk48;
    }
    func_00575018((void *) arg0, 2);
    if (var_s0 != 0) {
        free(var_s0);
    }
}
