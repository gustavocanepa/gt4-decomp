#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0047E4E8();                            /* extern */
s32 func_0047E5F8(s32, s32, s32, f32);          /* extern */

struct func_00474E08_arg0 {
    char pad0[0x20];
    f32 unk20;
};
struct func_00474E08_arg1 {
    char pad0[0x20];
    f32 unk20;
};
struct func_00474E08_arg2 {
    char pad0[0x20];
    f32 unk20;
};

void func_00474E08(void *arg0, void *arg1, void *arg2, f32 fparg0) {
    func_0047E4E8();
    func_0047E5F8(arg0 + 0x18, arg1 + 0x18, arg2 + 0x18, fparg0);
    ((struct func_00474E08_arg0 *)arg0)->unk20 = (f32) ((((struct func_00474E08_arg1 *)arg1)->unk20 * (1.0f - fparg0)) + (((struct func_00474E08_arg2 *)arg2)->unk20 * fparg0));
}
