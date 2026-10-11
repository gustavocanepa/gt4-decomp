#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FD840_arg0 {
    char pad0[0x1E668];
    s32 unk1E668;
};

void func_005FD840(struct func_005FD840_arg0 *arg0, s32 arg1) {
    arg0->unk1E668 = arg1;
}
