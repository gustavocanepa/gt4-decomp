#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046D770(void *);                          /* extern */
s8 func_0046E978(s32);                              /* extern */
s32 func_0046EA08(s32);                             /* extern */

struct func_0046DE10_arg0 {
    char pad0[0xAD0];
    s32 unkAD0;
    char padAD4[0x8];
    s8 unkADC;
    s8 unkADD;
    char padADE[0x6];
    s32 unkAE4;
    s32 unkAE8;
    s32 unkAEC;
    s32 unkAF0;
    s32 unkAF4;
    char padAF8[0x2E4];
    s32 unkDDC;
};

s32 func_0046DE10(void *arg0) {
    s32 temp_s0;

    temp_s0 = arg0 + 0xA88;
    ((struct func_0046DE10_arg0 *)arg0)->unkAD0 = 0;
    ((struct func_0046DE10_arg0 *)arg0)->unkADC = func_0046E978(temp_s0);
    ((struct func_0046DE10_arg0 *)arg0)->unkADD = func_0046E978(temp_s0);
    ((struct func_0046DE10_arg0 *)arg0)->unkAE4 = func_0046E978(temp_s0);
    ((struct func_0046DE10_arg0 *)arg0)->unkAE8 = func_0046EA08(temp_s0);
    ((struct func_0046DE10_arg0 *)arg0)->unkAEC = func_0046EA08(temp_s0);
    ((struct func_0046DE10_arg0 *)arg0)->unkAF0 = func_0046E978(temp_s0);
    ((struct func_0046DE10_arg0 *)arg0)->unkAF4 = func_0046E978(temp_s0);
    if (func_0046D770(arg0) != 0) {
        ((struct func_0046DE10_arg0 *)arg0)->unkDDC = (s32) (((struct func_0046DE10_arg0 *)arg0)->unkDDC | 1);
        return 1;
    }
    return 0;
}
