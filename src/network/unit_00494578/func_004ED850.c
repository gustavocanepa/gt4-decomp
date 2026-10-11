/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004ED850_arg0_unk50 {
    char pad0[0x1000];
    s8 unk1000;
    char pad1001[0xFF];
    s8 unk1100;
    char pad1101[0xFF];
    s8 unk1200;
    char pad1201[0x10F];
    s32 unk1310;
    s32 unk1314;
    s32 unk1318;
};
struct func_004ED850_arg0 {
    char pad0[0x50];
    struct func_004ED850_arg0_unk50 *unk50;
};

void func_004ED850(struct func_004ED850_arg0 *arg0, s32 arg1) {
    arg0->unk50->unk1000 = 0;
    arg0->unk50->unk1100 = 0;
    arg0->unk50->unk1200 = 0;
    arg0->unk50->unk1310 = arg1;
    arg0->unk50->unk1314 = -1;
    arg0->unk50->unk1318 = -1;
}
