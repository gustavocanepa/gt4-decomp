#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 SPEC_DATABASE__DatabaseStorage__getRow(s32, s64, s32, void *);   /* extern */

extern char D_006235A8[];
struct func_004400D0_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_004400D0_temp_a3 {
    char pad0[0xE8];
    s64 unkE8;
};

void func_004400D0(char *arg0, s32 arg1) {
    char *temp_a3;

    temp_a3 = arg0 + (((struct func_004400D0_arg0 *)arg0)->unk490 * 0x178);
    SPEC_DATABASE__DatabaseStorage__getRow((s32)D_006235A8, ((struct func_004400D0_temp_a3 *)temp_a3)->unkE8, arg1 + 0x11A, temp_a3);
}

}
