#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_001C97D8_arg1 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};
struct func_001C97D8_arg0 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
};

void func_001C97D8(struct func_001C97D8_arg0 *arg0, struct func_001C97D8_arg1 *arg1) {
    s32 temp_v0;
    u8 temp_a3;

    temp_a3 = arg1->unk3;
    temp_v0 = 0xFF - temp_a3;
    arg0->unk0 = (u8) ((s32) ((arg0->unk0 * temp_v0) + (arg1->unk2 * temp_a3)) >> 8);
    arg0->unk1 = (u8) ((s32) ((arg0->unk1 * temp_v0) + (arg1->unk1 * arg1->unk3)) >> 8);
    arg0->unk2 = (u8) ((s32) ((arg0->unk2 * temp_v0) + (arg1->unk0 * arg1->unk3)) >> 8);
}
