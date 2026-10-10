#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00378AE0();                            /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */

extern char D_0067B990[];
struct func_00384510_arg0 {
    s32 unk0;
    char pad4[0x17C];
    s32 unk180;
    char pad184[0x4];
    f32 unk188;
    char pad18C[0x4];
    f32 unk190;
};

void func_00384510(void *arg0) {
    func_00378AE0();
    ((struct func_00384510_arg0 *)arg0)->unk180 = 0;
    ((struct func_00384510_arg0 *)arg0)->unk0 = (s32)D_0067B990;
    func_005A48D8(arg0 + 0x184, 0, 0xC);
    ((struct func_00384510_arg0 *)arg0)->unk188 = 0x1.9000000000000p+6f;
    ((struct func_00384510_arg0 *)arg0)->unk190 = 0x1.47ae140000000p-6f;
}
