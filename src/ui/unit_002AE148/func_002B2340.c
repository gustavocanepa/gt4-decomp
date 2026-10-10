/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_002B1FE0();                                /* extern */
f32 func_002B2128();                                /* extern */

struct func_002B2340_arg0 {
    char pad0[0xF8];
    f32 unkF8;
    char padFC[0x20];
    s32 unk11C;
};

f32 func_002B2340(struct func_002B2340_arg0 *arg0) {
    if (arg0->unk11C != 0) {
        return func_002B2128();
    }
    return func_002B1FE0() * arg0->unkF8;
}
