#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005FAC70_arg0 {
    char pad0[0x3454];
    s32 unk3454;
};

void func_005FAC70(struct func_005FAC70_arg0 *arg0, s32 arg1) {
    arg0->unk3454 = (s32) (arg1 != 0);
}
