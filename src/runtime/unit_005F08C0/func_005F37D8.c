#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F37D8_arg0 {
    char pad0[0x8C];
    s32 unk8C;
};

void *func_005F37D8(void *arg0) {
    return arg0 + ((1 - ((struct func_005F37D8_arg0 *)arg0)->unk8C) * 0x44) + 4;
}
