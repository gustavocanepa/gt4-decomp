/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FAC30(s32, void *);                 /* extern */
s32 func_00503300(s32, s32, s32);           /* extern */

struct func_004FF670_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    char padC[0x8];
    s32 unk14;
};

void func_004FF670(struct func_004FF670_arg0 *arg0) {
    func_004FAC30(arg0->unk14, arg0);
    func_00503300(arg0->unk8, arg0->unk4, 0);
}
