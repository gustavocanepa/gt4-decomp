#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005CCC18_arg0_unk10 {
    char pad0[0x1144];
    s32 unk1144;
};
struct func_005CCC18_arg0 {
    char pad0[0x10];
    struct func_005CCC18_arg0_unk10 *unk10;
};

s32 func_005CCC18(struct func_005CCC18_arg0 *arg0) {
    return arg0->unk10->unk1144;
}
