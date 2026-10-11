#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E5CB8_arg0 {
    char pad0[0x130];
    f32 unk130;
};

void func_005E5CB8(struct func_005E5CB8_arg0 *arg0, f32 fparg0) {
    arg0->unk130 = fparg0;
}
