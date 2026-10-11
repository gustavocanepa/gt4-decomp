#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004421D0_arg1 {
    char pad0[0x168];
    u8 unk168;
    u8 unk169;
    u8 unk16A;
    u8 unk16B;
    u8 unk16C;
    u8 unk16D;
    u8 unk16E;
    u8 unk16F;
};
struct func_004421D0_arg2 {
    char pad0[0x3];
    u8 unk3;
    char pad4[0xB];
    u8 unkF;
};
struct func_004421D0_arg0 {
    char pad0[0x150];
    u8 unk150;
    u8 unk151;
    u8 unk152;
    u8 unk153;
    u8 unk154;
    u8 unk155;
};

void func_004421D0(struct func_004421D0_arg0 *arg0, struct func_004421D0_arg1 *arg1, struct func_004421D0_arg2 *arg2) {
    arg1->unk168 = (u8) arg2->unk3;
    arg1->unk169 = (u8) arg2->unkF;
    arg1->unk16A = (u8) arg0->unk150;
    arg1->unk16B = (u8) arg0->unk151;
    arg1->unk16C = (u8) arg0->unk152;
    arg1->unk16D = (u8) arg0->unk153;
    arg1->unk16E = (u8) arg0->unk154;
    arg1->unk16F = (u8) arg0->unk155;
}
