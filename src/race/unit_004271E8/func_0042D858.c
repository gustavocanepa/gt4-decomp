#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0042D858_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
    f32 unkC;
};

void func_0042D858(struct func_0042D858_arg0 *arg0, f32 fparg0) {
    arg0->unk8 = 1;
    arg0->unk0 = 1;
    arg0->unkC = (f32) ((fparg0 * 0x1.6800000000000p+7f) / 0x1.921fb40000000p+1f);
}
