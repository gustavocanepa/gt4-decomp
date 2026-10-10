#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00478BE0(s32);                         /* extern */
s32 func_0047EEE8(s32, void *);                 /* extern */

struct func_0047EE00_arg1 {
    char pad0[0x6E20];
    void *unk6E20;
};
struct func_0047EE00_arg0 {
    s16 unk0;
    char pad2[0x2];
    s32 unk4;
};

void func_0047EE00(void *arg0, void *arg1) {
    func_00478BE0(M2C_FIELD(((struct func_0047EE00_arg1 *)arg1)->unk6E20, s32 *, 0x68) + (((struct func_0047EE00_arg0 *)arg0)->unk0 * 8));
    func_0047EEE8(((struct func_0047EE00_arg0 *)arg0)->unk4, arg1);
}
