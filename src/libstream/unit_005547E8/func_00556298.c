#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00561170(s32);                         /* extern */

struct func_00556298_arg1 {
    char pad0[0x3C];
    s32 unk3C;
};

s32 func_00556298(s32 arg0, struct func_00556298_arg1 *arg1) {
    func_00561170(arg1->unk3C);
    return arg1->unk3C;
}
