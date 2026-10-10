#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_00359568(s32);                             /* extern */

struct func_00366300_arg0 {
    char pad0[0x10];
    f32 unk10;
};

f32 func_00366300(void *arg0) {
    return func_00359568(arg0 + 0x24) * ((struct func_00366300_arg0 *)arg0)->unk10;
}
