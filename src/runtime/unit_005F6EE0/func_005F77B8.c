#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F77B8_arg0 {
    char pad0[0x60];
    s32 unk60;
};

s32 func_005F77B8(struct func_005F77B8_arg0 *arg0, s32 arg1) {
    return (arg0->unk60 & arg1) != 0;
}
