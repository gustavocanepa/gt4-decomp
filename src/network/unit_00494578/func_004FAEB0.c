/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FA0E0(void *, s32);             /* extern */
s32 func_004FAE60();                            /* extern */

struct func_004FAEB0_arg0 {
    char pad0[0xFC8];
    s32 unkFC8;
    s32 unkFCC;
};

void func_004FAEB0(struct func_004FAEB0_arg0 *arg0) {
    arg0->unkFC8 = 0;
    arg0->unkFCC = 0;
    func_004FAE60();
    func_004FA0E0(arg0, 0);
}
