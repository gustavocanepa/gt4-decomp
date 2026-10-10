#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_004AC118(f32, f32);                        /* extern */

struct func_0036EA98_arg0 {
    f32 unk0;
    char pad4[0x4];
    f32 unk8;
};

f32 func_0036EA98(struct func_0036EA98_arg0 *arg0) {
    return (0x1.921fb40000000p+1f - func_004AC118(arg0->unk0, arg0->unk8)) * 0x1.ca5dc00000000p+5f;
}
