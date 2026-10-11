#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00452A90(f32, f32, f32, f32);          /* extern */
s32 func_00452AB0(f32, f32);                    /* extern */

struct func_00398718_arg0 {
    char pad0[0x17B4];
    f32 unk17B4;
    f32 unk17B8;
    f32 unk17BC;
    f32 unk17C0;
    f32 unk17C4;
    f32 unk17C8;
};

void func_00398718(void *arg0) {
    func_00452A90(((struct func_00398718_arg0 *)arg0)->unk17B4, ((struct func_00398718_arg0 *)arg0)->unk17B8, ((struct func_00398718_arg0 *)arg0)->unk17BC, ((struct func_00398718_arg0 *)arg0)->unk17C0);
    func_00452AB0(((struct func_00398718_arg0 *)arg0)->unk17C4, ((struct func_00398718_arg0 *)arg0)->unk17C8);
}
