#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F5C00_arg0 {
    char pad0[0x269];
    u8 unk269;
    char pad26A[0x1];
    u8 unk26B;
};

s32 func_005F5C00(struct func_005F5C00_arg0 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((arg0->unk26B != 0) || (arg0->unk269 != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}
