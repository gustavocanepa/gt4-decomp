#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003CC7F8_arg0 {
    char pad0[0x96D4];
    s32 unk96D4;
};

void func_003CC7F8(struct func_003CC7F8_arg0 *arg0, s32 arg1) {
    arg0->unk96D4 = arg1;
}
