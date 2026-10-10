#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00601478_arg0 {
    char pad0[0x81F0];
    s32 unk81F0;
};

void func_00601478(struct func_00601478_arg0 *arg0, s32 arg1) {
    arg0->unk81F0 = arg1;
}
