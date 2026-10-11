/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00578480(s32);                         /* extern */

struct func_00548428_arg0 {
    char pad0[0x3C];
    s32 unk3C;
    s32 unk40;
};

void func_00548428(struct func_00548428_arg0 *arg0) {
    if (arg0->unk3C != 0) {
        arg0->unk3C = 0;
        func_00578480(arg0->unk40);
    }
}
