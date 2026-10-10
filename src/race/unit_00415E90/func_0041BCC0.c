#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0041B540(s32, f32);                        /* extern */
s32 func_0041B678();                                /* extern */

struct func_0041BCC0_arg0 {
    char pad0[0x30];
    f32 unk30;
    f32 unk34;
    f32 unk38;
};

void func_0041BCC0(struct func_0041BCC0_arg0 *arg0) {
    func_0041B540(func_0041B540(func_0041B540(func_0041B678(), arg0->unk30), arg0->unk34), arg0->unk38);
}
