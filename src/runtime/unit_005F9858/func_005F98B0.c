#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F98B0_arg0 {
    char pad0[0x8C];
    f32 unk8C;
};

void func_005F98B0(struct func_005F98B0_arg0 *arg0, f32 fparg0) {
    arg0->unk8C = fparg0;
}
