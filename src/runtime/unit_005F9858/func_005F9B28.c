#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F9B28_arg0 {
    char pad0[0x50];
    s32 unk50;
};

void func_005F9B28(struct func_005F9B28_arg0 *arg0, s32 arg1) {
    arg0->unk50 = (s32) ((arg0->unk50 & 0xFFFF00FF) | ((arg1 & 0xFF) << 8));
}
