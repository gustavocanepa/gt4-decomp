#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0057D6C0(f32, f32);
struct func_0039A560_arg0 {
    char pad0[0x10];
    f32 unk10;
};

f32 func_0039A560(struct func_0039A560_arg0 *arg0, f32 fparg0) {
    f32 temp_f20;

    temp_f20 = arg0->unk10;
    arg0->unk10 = func_0057D6C0(0x1.4000000000000p+3f, fparg0 / 0x1.4000000000000p+4f);
    return temp_f20;
}
