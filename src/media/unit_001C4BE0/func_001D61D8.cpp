#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A7844(f32, f32, f32);               /* extern */
s32 func_004A7988(f32);                         /* extern */
s32 func_004A79B0(f32);                         /* extern */
s32 func_004A79D8(f32);                         /* extern */

struct func_001D61D8_arg0 {
    char pad0[0x40];
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
};

void func_001D61D8(void *arg0) {
    func_004A7844(((struct func_001D61D8_arg0 *)arg0)->unk40, ((struct func_001D61D8_arg0 *)arg0)->unk44, ((struct func_001D61D8_arg0 *)arg0)->unk48);
    func_004A79D8(((struct func_001D61D8_arg0 *)arg0)->unk54);
    func_004A7988(((struct func_001D61D8_arg0 *)arg0)->unk4C);
    func_004A79B0(((struct func_001D61D8_arg0 *)arg0)->unk50);
}
