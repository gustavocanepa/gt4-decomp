#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {

void func_00100BB8(s32);
void func_00107AB8(s32);
void func_003DA0B8(void *, s32);
struct func_003D8A60_arg0 {
    char pad0[0x24];
    s32 unk24;
    s32 unk28;
    char pad2C[0x8];
    s32 unk34;
};

void func_003D8A60(struct func_003D8A60_arg0 *arg0) {
    arg0->unk24 = 1;
    if ((arg0->unk28 == 1) || (arg0->unk34 == 1)) {
        func_003DA0B8(arg0, 1);
        func_00107AB8(1);
        func_00100BB8(2);
    }
}

}
