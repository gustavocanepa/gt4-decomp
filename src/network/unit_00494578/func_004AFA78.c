#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004AFA78_arg0_unk4 {
    char pad0[0x38];
    s32 unk38;
};
struct func_004AFA78_arg0 {
    char pad0[0x4];
    struct func_004AFA78_arg0_unk4 *unk4;
};

s32 func_004AFA78(struct func_004AFA78_arg0 *arg0) {
    return arg0->unk4->unk38;
}
