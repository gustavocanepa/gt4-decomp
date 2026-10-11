#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00612E58_arg0 {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
};

void func_00612E58(struct func_00612E58_arg0 *arg0) {
    arg0->unk2C = (s32) arg0->unk28;
}
