/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_005FF8D8_arg0 {
    char pad0[0x68];
    f32 unk68;
    f32 unk6C;
};

void func_005FF8D8(struct func_005FF8D8_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk68 = fparg0;
    arg0->unk6C = fparg1;
}
