/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_005FB628_arg0 {
    char pad0[0x50];
    f32 unk50;
    f32 unk54;
};

void func_005FB628(struct func_005FB628_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk50 = fparg0;
    arg0->unk54 = fparg1;
}
