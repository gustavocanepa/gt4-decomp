#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00479688_arg0_unk0 {
    char pad0[0x60];
    s32 unk60;
};
struct func_00479688_arg0_unk4 {
    char pad0[0x6];
    s16 unk6;
};
struct func_00479688_arg0 {
    struct func_00479688_arg0_unk0 *unk0;
    struct func_00479688_arg0_unk4 *unk4;
};

s32 func_00479688(struct func_00479688_arg0 *arg0) {
    return arg0->unk0->unk60 + (arg0->unk4->unk6 * 0x34);
}
