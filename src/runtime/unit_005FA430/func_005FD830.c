#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FD830_arg0 {
    char pad0[0x1E650];
    s32 unk1E650;
};

void func_005FD830(struct func_005FD830_arg0 *arg0, s32 arg1) {
    arg0->unk1E650 = arg1;
}
