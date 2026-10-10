#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F77F0_arg0 {
    char pad0[0x34];
    s32 unk34;
};

void func_005F77F0(struct func_005F77F0_arg0 *arg0, s32 arg1) {
    arg0->unk34 = (s32) ((arg0->unk34 & 0xFF00FFFF) | ((arg1 & 0xFF) << 0x10));
}
