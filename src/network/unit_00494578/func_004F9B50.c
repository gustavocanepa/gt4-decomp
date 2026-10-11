/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00576100();                            /* extern */
s32 func_00576140(void *);                      /* extern */

struct func_004F9B50_arg0 {
    char pad0[0xFC0];
    s32 unkFC0;
    s32 unkFC4;
};

void func_004F9B50(struct func_004F9B50_arg0 *arg0) {
    func_00576100();
    arg0->unkFC0 = 0;
    arg0->unkFC4 = 0;
    func_00576140(arg0);
}
