#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 HCodeFrame__structor_0(s32, s32);                    /* extern */
s32 func_003217D0(s32, s32, s32, s32, s32);     /* extern */

struct hScriptMethod__virtual_14_arg0 {
    char pad0[0xC];
    s32 unkC;
};

void hScriptMethod__virtual_14(char *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    HCodeFrame__structor_0(*arg1, (s32)(arg0 + 0xC));
    func_003217D0(*arg1, ((struct hScriptMethod__virtual_14_arg0 *)arg0)->unkC + 0x10, arg3, arg4, arg2);
}

}
