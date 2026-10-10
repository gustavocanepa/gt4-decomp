#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_002A65A0_arg0 {
    char pad0[0x164];
    s32 unk164;
};

s32 func_002A65A0(struct func_002A65A0_arg0 *arg0) {
    return arg0->unk164 == 8;
}
