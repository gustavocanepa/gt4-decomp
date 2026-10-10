#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 HCodeFrame__structor_0(s32, s32);                    /* extern */
s32 hThread__setArguments(s32, s32, s32, s32, s32);     /* extern */

struct hScriptMethod__virtual_14_arg0 {
    char pad0[0xC];
    s32 unkC;
};

void hScriptMethod__call_const_2(char *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    HCodeFrame__structor_0(*arg1, (s32)(arg0 + 0xC));
    hThread__setArguments(*arg1, ((struct hScriptMethod__virtual_14_arg0 *)arg0)->unkC + 0x10, arg3, arg4, arg2);
}

}
