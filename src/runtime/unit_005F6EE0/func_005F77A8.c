#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F77A8_arg0 {
    char pad0[0x5C];
    s32 unk5C;
};

s32 func_005F77A8(struct func_005F77A8_arg0 *arg0, s32 arg1) {
    return (arg0->unk5C & arg1) != 0;
}
