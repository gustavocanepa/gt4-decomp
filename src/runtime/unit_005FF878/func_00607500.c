#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00607500_arg0_unk4 {
    char pad0[0xA];
    u16 unkA;
};
struct func_00607500_arg0 {
    char pad0[0x4];
    struct func_00607500_arg0_unk4 *unk4;
};

u16 func_00607500(struct func_00607500_arg0 *arg0) {
    return arg0->unk4->unkA;
}
