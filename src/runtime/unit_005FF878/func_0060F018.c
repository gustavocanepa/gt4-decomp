#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004F9E60(void *, s32);
s32 func_004F9EC0(void *, s32);                 /* extern */

struct func_0060F018_arg0 {
    char pad0[0xCC4];
    s32 unkCC4;
};

void func_0060F018(struct func_0060F018_arg0 *arg0) {
    func_004F9EC0(arg0, func_004F9E60(arg0, arg0->unkCC4));
}
