#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00868820[];
s32 func_00535488(s32 arg0) {
    s32 var_v0;

    var_v0 = 0xA;
    if (arg0 != 0) {
        func_005A4724(arg0, (s32)D_00868820, 0x28);
        var_v0 = 0;
    }
    return var_v0;
}
