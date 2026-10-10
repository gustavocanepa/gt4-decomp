#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00436790_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

s32 func_00436790(struct func_00436790_arg0 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((arg0->unk0 == 0) && (arg0->unk4 == 0) && (arg0->unk8 == 0)) {
        var_v1 = arg0->unkC == 0;
    }
    return var_v1;
}
