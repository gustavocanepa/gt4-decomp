#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
f32 func_00455000(void *, f32);                     /* extern */

static inline f32 call_00455000(void *p, f32 x) { return func_00455000(p, x); }

struct func_00456758_arg0 {
    char pad0[0x16];
    u16 unk16;
    char pad18[0x20];
    s32 unk38;
};
struct func_00456758_temp_a0 {
    char pad0[0x8];
    f32 unk8;
};

f32 func_00456758(char *arg0, s32 arg1) {
    char *temp_a0;

    if ((arg1 >= (s32) ((struct func_00456758_arg0 *)arg0)->unk16) || (arg1 < 0)) {
        return 0x0.0p+0f;
    }
    temp_a0 = (char *)(((struct func_00456758_arg0 *)arg0)->unk38 + (arg1 * 0x28));
    return call_00455000(temp_a0 + 0xC, ((struct func_00456758_temp_a0 *)temp_a0)->unk8);
}

}
