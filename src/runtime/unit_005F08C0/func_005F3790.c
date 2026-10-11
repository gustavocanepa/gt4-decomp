#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F3790_arg0 {
    char pad0[0x8C];
    s32 unk8C;
};

void *func_005F3790(void *arg0) {
    return arg0 + (((struct func_005F3790_arg0 *)arg0)->unk8C * 0x44) + 4;
}
