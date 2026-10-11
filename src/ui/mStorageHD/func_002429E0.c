#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_002429E0_arg0 {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
};
struct func_002429E0_arg1 {
    char pad0[0x1];
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
};

void func_002429E0(struct func_002429E0_arg0 *arg0, struct func_002429E0_arg1 *arg1) {
    arg0->unk0 = (s16) (arg1->unk6 + (arg1->unk7 << 8));
    arg0->unk2 = (u8) arg1->unk5;
    arg0->unk3 = (u8) arg1->unk4;
    arg0->unk4 = (u8) arg1->unk3;
    arg0->unk5 = (u8) arg1->unk2;
    arg0->unk6 = (u8) arg1->unk1;
}
