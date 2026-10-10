#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00364DD0(s32, s32);                    /* extern */

struct func_00459D18_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_00459D18(void *arg0, s32 arg1) {
    func_00364DD0(((struct func_00459D18_arg0 *)arg0)->unk4, M2C_FIELD(((arg1 * 0x10) + arg0), s32 *, 0x1C));
}
