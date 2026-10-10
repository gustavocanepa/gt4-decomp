/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00518FA8(void *);                      /* extern */
void *func_0051B8A8();                              /* extern */
void *func_0051B968(s32, s32);                      /* extern */
s32 func_0051BAE0(s32, s32);                /* extern */

struct func_00518E68_var_s1 {
    char pad0[0x4];
    s32 unk4;
};

void func_00518E68(s32 arg0, s32 arg1) {
    struct func_00518E68_var_s1 *var_s1;

    var_s1 = func_0051B8A8();
    if ((var_s1 != NULL) || (var_s1 = func_0051B968(arg0, arg1), (var_s1 != NULL))) {
        var_s1->unk4 = 0x1000;
        func_0051BAE0(arg0, -1);
        func_00518FA8(var_s1);
    }
}
