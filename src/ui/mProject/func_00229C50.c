#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

u16 func_00206860(void);
u16 func_0025C2F8(u16);
s32 func_00265F70(u16);
s32 func_00229C50(void) {
    u16 var_s0;
    var_s0 = func_00206860();
    while (var_s0 != 0) {
        if (func_00265F70(var_s0) != 0) {
            return 1;
        }
        var_s0 = func_0025C2F8(var_s0);
    }
    return 0;
}
