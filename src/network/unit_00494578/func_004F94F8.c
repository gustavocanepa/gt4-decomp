/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F8978(void *);                      /* extern */
s32 func_004F9538(void *);                      /* extern */
s32 func_004F9570();                            /* extern */
s32 func_004F9CE8(void *);                      /* extern */

struct func_004F94F8_arg0 {
    char pad0[0xF68];
    s32 unkF68;
};

void func_004F94F8(void *arg0) {
    func_004F9570();
    func_004F9538(arg0);
    func_004F8978(arg0 + 0xCD8);
    ((struct func_004F94F8_arg0 *)arg0)->unkF68 = 0;
    func_004F9CE8(arg0);
}
