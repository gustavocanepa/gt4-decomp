#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0042E008(f32, f32, f32, f32);          /* extern */
s32 func_004AA168(s32);                         /* extern */

struct func_0042E1F0_arg0 {
    char pad0[0xC];
    s32 unkC;
    char pad10[0xC];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
};

void func_0042E1F0(void *arg0) {
    func_004AA168(((struct func_0042E1F0_arg0 *)arg0)->unkC);
    func_0042E008(((struct func_0042E1F0_arg0 *)arg0)->unk1C, ((struct func_0042E1F0_arg0 *)arg0)->unk20, ((struct func_0042E1F0_arg0 *)arg0)->unk24, ((struct func_0042E1F0_arg0 *)arg0)->unk28);
}
