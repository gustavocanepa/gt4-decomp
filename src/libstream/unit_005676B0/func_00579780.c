#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005797A8(s16, u8, u8);                 /* extern */

struct func_00579780_arg0 {
    s16 unk0;
    u8 unk2;
    u8 unk3;
};

void func_00579780(struct func_00579780_arg0 *arg0) {
    func_005797A8(arg0->unk0, arg0->unk2, arg0->unk3);
}
