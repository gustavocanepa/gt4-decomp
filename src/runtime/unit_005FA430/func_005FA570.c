/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_005FA570_arg0 {
    char pad0[0x20];
    f32 unk20;
    f32 unk24;
};

void func_005FA570(struct func_005FA570_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk20 = fparg0;
    arg0->unk24 = fparg1;
}
