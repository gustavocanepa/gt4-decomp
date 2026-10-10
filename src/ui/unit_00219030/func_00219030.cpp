#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_00213158(...);                          /* extern */
s32 func_00305548(void *);                          /* extern */
s32 func_00306130(s32, s32);                    /* extern */

struct func_00219030_temp_s1 {
    char pad0[0x4];
    void *unk4;
};
struct func_00219030_temp_s0 {
    char pad0[0x2C8];
    s16 unk2C8;
};
struct func_00219030_temp_s0_2 {
    char pad0[0x4];
    s32 (*unk4)(void *, s32);
};
struct func_00219030_temp_s1_3 {
    char pad0[0x4];
    void *unk4;
};
struct func_00219030_temp_s0_3 {
    char pad0[0x2B8];
    s16 unk2B8;
};
struct func_00219030_temp_s0_4 {
    char pad0[0x4];
    s32 (*unk4)(void *, s32);
};
struct func_00219030_arg0 {
    char pad0[0x24];
    s32 unk24;
};

void func_00219030(char *arg0, char **arg1, s32 arg2) {
    char *temp_s0;
    char *temp_s0_2;
    char *temp_s0_3;
    char *temp_s0_4;
    char *temp_s1;
    char *temp_s1_2;
    char *temp_s1_3;
    char *temp_s1_4;

    if (arg2 != 0) {
        temp_s1 = *arg1;
        temp_s0 = (char *)(((struct func_00219030_temp_s1 *)temp_s1)->unk4);
        temp_s0_2 = temp_s0 + 0x2C8;
        temp_s1_2 = temp_s1 + ((struct func_00219030_temp_s0 *)temp_s0)->unk2C8;
        ((struct func_00219030_temp_s0_2 *)temp_s0_2)->unk4(temp_s1_2, func_00213158());
        temp_s1_3 = *arg1;
        temp_s0_3 = (char *)(((struct func_00219030_temp_s1_3 *)temp_s1_3)->unk4);
        temp_s0_4 = temp_s0_3 + 0x2B8;
        temp_s1_4 = temp_s1_3 + ((struct func_00219030_temp_s0_3 *)temp_s0_3)->unk2B8;
        ((struct func_00219030_temp_s0_4 *)temp_s0_4)->unk4(temp_s1_4, func_00213158(arg0));
    }
    func_00306130(((struct func_00219030_arg0 *)arg0)->unk24, func_00305548(*arg1));
}

}
