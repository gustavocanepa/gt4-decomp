#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 SPEC_DATABASE__DatabaseStorage__getRow(s32, s64, s32, void *);   /* extern */

extern char D_006235A8[];
struct func_0043FE58_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_0043FE58_temp_a3 {
    char pad0[0x30];
    s64 unk30;
};

void func_0043FE58(char *arg0, s32 arg1) {
    char *temp_a3;

    temp_a3 = arg0 + (((struct func_0043FE58_arg0 *)arg0)->unk490 * 0x178);
    SPEC_DATABASE__DatabaseStorage__getRow((s32)D_006235A8, ((struct func_0043FE58_temp_a3 *)temp_a3)->unk30, arg1, temp_a3);
}

}
