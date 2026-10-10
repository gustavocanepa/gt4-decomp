#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00601498_arg0 {
    char pad0[0x81E0];
    s32 unk81E0;
};

void func_00601498(struct func_00601498_arg0 *arg0, s32 arg1) {
    arg0->unk81E0 = arg1;
}
