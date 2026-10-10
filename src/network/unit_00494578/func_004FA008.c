#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F9E60(void *, s32);
s32 func_004F9EC0(void *, s32);                     /* extern */
s32 func_004F9F70(void *, s32);                 /* extern */

struct func_004FA008_arg0 {
    char pad0[0xCC4];
    s32 unkCC4;
};

void func_004FA008(struct func_004FA008_arg0 *arg0) {
    func_004F9F70(arg0, func_004F9EC0(arg0, func_004F9E60(arg0, arg0->unkCC4)));
}
