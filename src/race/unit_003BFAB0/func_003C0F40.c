#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003C0F40_arg0 {
    char pad0[0xD4];
    f32 unkD4;
    f32 unkD8;
};

void func_003C0F40(struct func_003C0F40_arg0 *arg0, f32 fparg0, f32 fparg1) {
    s32 var_v0;

    var_v0 = 1;
    if (!(arg0->unkD4 >= 0.0f)) {
        var_v0 = 0;
    }
    if (var_v0 == 0) {
        arg0->unkD4 = fparg0;
        if (fparg0 <= 0.0f) {
            arg0->unkD4 = 0.016666666f;
        }
        arg0->unkD8 = fparg1;
    }
}
