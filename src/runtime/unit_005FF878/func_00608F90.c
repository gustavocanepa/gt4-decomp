#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00608F90_arg0 {
    char pad0[0x70];
    s32 unk70;
};

void func_00608F90(struct func_00608F90_arg0 *arg0) {
    arg0->unk70 = 1;
}
