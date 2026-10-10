#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F6668_arg0_unk6C {
    char pad0[0x80];
    s32 unk80;
};
struct func_005F6668_arg0 {
    char pad0[0x6C];
    struct func_005F6668_arg0_unk6C *unk6C;
};

s32 func_005F6668(struct func_005F6668_arg0 *arg0) {
    return arg0->unk6C->unk80;
}
