#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00604D20_arg0 {
    char pad0[0x2DC];
    s32 unk2DC;
};

void *func_00604D20(void *arg0) {
    return ((1 - ((struct func_00604D20_arg0 *)arg0)->unk2DC) * 0x16C) + arg0 + 4;
}
