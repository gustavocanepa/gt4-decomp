#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004ADBA8_arg1 {
    char pad0[0x84];
    s32 unk84;
};

void func_004ADBA8(s32 arg0, struct func_004ADBA8_arg1 *arg1) {
    arg1->unk84 = 2;
}
