#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0041B540(s32, f32);                        /* extern */
s32 func_0041BCC0();                                /* extern */

struct func_0041C0B8_arg0 {
    char pad0[0x50];
    f32 unk50;
    f32 unk54;
    f32 unk58;
    char pad5C[0x4];
    f32 unk60;
    f32 unk64;
    f32 unk68;
};

void func_0041C0B8(struct func_0041C0B8_arg0 *arg0) {
    func_0041B540(func_0041B540(func_0041B540(func_0041B540(func_0041B540(func_0041B540(func_0041BCC0(), arg0->unk50), arg0->unk54), arg0->unk58), arg0->unk60), arg0->unk64), arg0->unk68);
}
