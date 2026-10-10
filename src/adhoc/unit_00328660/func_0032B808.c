#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0057F260(s32);                             /* extern */
s32 func_005C2630(void **, s32, s32, s32, s32); /* extern */

void **func_0032B808(void **arg0, s32 arg1) {
    func_005C2630(arg0, M2C_FIELD(*arg0, s32 *, -0x10), 0, arg1, func_0057F260(arg1));
    return arg0;
}
