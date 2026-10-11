/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005D8480_arg0 {
    char pad0[0x2C];
    f32 unk2C;
    f32 unk30;
};

void func_005D8480(struct func_005D8480_arg0 *arg0, f32 fparg0) {
    arg0->unk30 = fparg0;
    arg0->unk2C = fparg0;
}
