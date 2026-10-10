#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F7898_arg0 {
    char pad0[0x3C];
    s32 unk3C;
};

void func_005F7898(struct func_005F7898_arg0 *arg0, s32 arg1) {
    arg0->unk3C = (s32) ((arg0->unk3C & 0xFFFF00FF) | ((arg1 & 0xFF) << 8));
}
