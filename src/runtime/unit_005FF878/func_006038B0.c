#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_006038B0_arg0_unkC {
    char pad0[0x4];
    s32 unk4;
};
struct func_006038B0_arg0 {
    char pad0[0xC];
    struct func_006038B0_arg0_unkC *unkC;
};

s32 func_006038B0(struct func_006038B0_arg0 *arg0) {
    return arg0->unkC->unk4;
}
