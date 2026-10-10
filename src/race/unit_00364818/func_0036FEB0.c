#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_0036FD98();                                /* extern */

struct func_0036FEB0_arg0 {
    char pad0[0x8];
    f32 unk8;
    f32 unkC;
    f32 unk10;
};

f32 func_0036FEB0(struct func_0036FEB0_arg0 *arg0) {
    return (func_0036FD98() * arg0->unk10 * arg0->unk8) / arg0->unkC;
}
