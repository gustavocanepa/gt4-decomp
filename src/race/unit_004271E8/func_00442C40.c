#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00442C40_arg1 {
    char pad0[0xBD];
    u8 unkBD;
    u8 unkBE;
    char padBF[0x4B];
    u16 unk10A;
    u8 unk10C;
    char pad10D[0x6];
    u8 unk113;
    char pad114[0x2];
    u8 unk116;
    u8 unk117;
    u8 unk118;
    u8 unk119;
    u8 unk11A;
    u8 unk11B;
};
struct func_00442C40_arg2 {
    char pad0[0x4];
    u16 unk4;
    u16 unk6;
    char pad8[0x1];
    u8 unk9;
    char padA[0x6];
    u8 unk10;
    u8 unk11;
};
struct func_00442C40_arg0 {
    char pad0[0x133];
    u8 unk133;
    u8 unk134;
    u8 unk135;
    u8 unk136;
    u8 unk137;
    u8 unk138;
};

void func_00442C40(struct func_00442C40_arg0 *arg0, struct func_00442C40_arg1 *arg1, struct func_00442C40_arg2 *arg2) {
    arg1->unk10A = (u16) ((s32) (arg1->unk10A * arg2->unk4) / 100);
    arg1->unk10C = (u8) ((s32) (arg1->unk10C * arg2->unk6) / 100);
    arg1->unk113 = (u8) arg2->unk9;
    arg1->unkBD = (u8) (arg1->unkBD + arg2->unk10);
    arg1->unkBE = (u8) (arg1->unkBE + arg2->unk11);
    arg1->unk118 = (u8) arg0->unk133;
    arg1->unk116 = (u8) arg0->unk134;
    arg1->unk11A = (u8) arg0->unk135;
    arg1->unk119 = (u8) arg0->unk136;
    arg1->unk117 = (u8) arg0->unk137;
    arg1->unk11B = (u8) arg0->unk138;
}
