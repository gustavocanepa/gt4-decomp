#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003A4650_arg0 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
};

void func_003A4650(struct func_003A4650_arg0 *arg0) {
    arg0->unk18 = 0;
    arg0->unk1C = 0;
}
