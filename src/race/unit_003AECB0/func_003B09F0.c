#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003B09F0_arg1 {
    char pad0[0x69C];
    f32 unk69C;
};

void func_003B09F0(f32 *arg0, struct func_003B09F0_arg1 *arg1) {
    *arg0 = arg1->unk69C;
}
