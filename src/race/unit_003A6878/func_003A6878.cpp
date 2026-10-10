#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_003A9738(void *, s32, s32);        /* extern */
s32 func_003A98E8(s32, f32, f32, f32, f32);     /* extern */

struct func_003A6878_arg0 {
    char pad0[0x1C];
    f32 unk1C;
    f32 unk20;
    s32 unk24;
};
struct func_003A6878_temp_a0 {
    char pad0[0x4];
    s32 unk4;
};

void func_003A6878(char *arg0, f32 fparg0, f32 fparg1) {
    char *temp_a0;

    func_003A98E8((s32)(arg0 + 0x28), fparg1, fparg0, ((struct func_003A6878_arg0 *)arg0)->unk1C, ((struct func_003A6878_arg0 *)arg0)->unk20);
    temp_a0 = arg0 + 0x44;
    ((struct func_003A6878_temp_a0 *)temp_a0)->unk4 = 0;
    func_003A9738(temp_a0, ((struct func_003A6878_arg0 *)arg0)->unk24, 1);
}

}
