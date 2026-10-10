/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00565B88(s32, s32, s32);       /* extern */

extern char D_00556610[];
extern char D_006550F8[];
void func_005565B0(s32 arg0) {
    func_00565B88((s32)D_006550F8, (s32)D_00556610, arg0);
}
