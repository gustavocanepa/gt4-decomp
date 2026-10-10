#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00579A70(u8, u8, u8);                  /* extern */

struct func_00579A48_arg0 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
};

void func_00579A48(struct func_00579A48_arg0 *arg0) {
    func_00579A70(arg0->unk0, arg0->unk1, arg0->unk2);
}
