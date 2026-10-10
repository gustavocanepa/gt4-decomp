#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_00443ED0(s32, s64, s32, void *);   /* extern */

extern char D_006235A8[];
struct func_00440030_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_00440030_temp_a3 {
    char pad0[0x60];
    s64 unk60;
};

void func_00440030(char *arg0, s32 arg1) {
    char *temp_a3;

    temp_a3 = arg0 + (((struct func_00440030_arg0 *)arg0)->unk490 * 0x178);
    func_00443ED0((s32)D_006235A8, ((struct func_00440030_temp_a3 *)temp_a3)->unk60, arg1 + 0xF4, temp_a3);
}

}
