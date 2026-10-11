/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FAC78(void *, void *);              /* extern */
s32 func_00503358(s32);                         /* extern */

struct func_004FF6B0_arg0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x8];
    void *unk14;
};
struct func_004FF6B0_temp_a0 {
    char pad0[0xFBC];
    s32 unkFBC;
};

void func_004FF6B0(struct func_004FF6B0_arg0 *arg0) {
    struct func_004FF6B0_temp_a0 *temp_a0;

    temp_a0 = arg0->unk14;
    temp_a0->unkFBC = 1;
    func_004FAC78(temp_a0, arg0);
    func_00503358(arg0->unk8);
}
