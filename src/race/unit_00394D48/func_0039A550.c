#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0039A550_arg0 {
    char pad0[0x10];
    f32 unk10;
};

f32 func_0039A550(struct func_0039A550_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;

    temp_f0 = arg0->unk10;
    arg0->unk10 = fparg0;
    return temp_f0;
}
