#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0047DF80_arg0 {
    f32 unk0;
    f32 unk4;
};
struct func_0047DF80_arg1 {
    f32 unk0;
    f32 unk4;
};

s32 func_0047DF80(struct func_0047DF80_arg0 *arg0, struct func_0047DF80_arg1 *arg1) {
    s32 var_v0;

    var_v0 = 0;
    if ((arg0->unk0 == arg1->unk0) && (arg0->unk4 == arg1->unk4)) {
        var_v0 = 1;
    }
    return var_v0;
}
