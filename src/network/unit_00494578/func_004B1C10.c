#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004B1600();                            /* extern */
s32 func_004B1A98(s32);                         /* extern */
s32 func_004B3790(void *);                      /* extern */

extern char D_00689268[];
struct func_004B1C10_temp_s2 {
    char pad0[0xC];
    s32 unkC;
};

struct func_004B1C10_arg0 {
    char pad0[0xA4];
    s32 unkA4;
    char padA8[0x44];
    s32 unkEC;
};

void func_004B1C10(void *arg0) {
    s32 temp_s1;
    struct func_004B1C10_temp_s2 *temp_s2;

    temp_s1 = arg0 + 0xE8;
    temp_s2 = arg0 + 0xC4;
    func_004B1600();
    ((struct func_004B1C10_arg0 *)arg0)->unkA4 = (s32)D_00689268;
    func_004B3790(temp_s2);
    func_004B1A98(temp_s1);
    ((struct func_004B1C10_arg0 *)arg0)->unkEC = 0;
    temp_s2->unkC = temp_s1;
}
