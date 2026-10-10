#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004756F8(s32 *);                       /* extern */
s32 func_0047FCF8(s32, s32 *);                  /* extern */

void func_004756C0(s32 *arg0) {
    func_0047FCF8(*arg0, arg0);
    func_004756F8(arg0);
}
