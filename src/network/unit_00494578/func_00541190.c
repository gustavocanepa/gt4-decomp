#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00541190_arg0 {
    char pad0[0x8C28];
    s32 unk8C28;
};

s32 func_00541190(struct func_00541190_arg0 *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 2;
    if (arg0 != NULL) {
        arg0->unk8C28 = arg1;
        var_v0 = 0;
    }
    return var_v0;
}
