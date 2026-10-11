#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00378AE0();                            /* extern */

extern char D_00686148[];
struct func_00400BB8_arg0 {
    s32 unk0;
    char pad4[0x194];
    s32 unk198;
};

void func_00400BB8(struct func_00400BB8_arg0 *arg0) {
    func_00378AE0();
    arg0->unk198 = 0;
    arg0->unk0 = (s32)D_00686148;
}
