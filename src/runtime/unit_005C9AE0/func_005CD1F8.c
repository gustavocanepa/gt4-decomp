#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005CD1F8_arg0_unk10 {
    char pad0[0x1694];
    s16 unk1694;
};
struct func_005CD1F8_arg0 {
    char pad0[0x10];
    struct func_005CD1F8_arg0_unk10 *unk10;
};

s16 func_005CD1F8(struct func_005CD1F8_arg0 *arg0) {
    return arg0->unk10->unk1694;
}
