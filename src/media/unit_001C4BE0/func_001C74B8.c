#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_00660DC8[];
s32 func_0046C050(void *);
struct func_001C74B8_arg0 {
    char pad0[0x8E8];
    s32 unk8E8;
    s32 unk8EC;
    s32 unk8F0;
    s32 unk8F4;
};

void func_001C74B8(struct func_001C74B8_arg0 *arg0) {
    func_0046C050(arg0);
    arg0->unk8E8 = (s32)D_00660DC8;
    arg0->unk8EC = 0;
    arg0->unk8F0 = 0;
    arg0->unk8F4 = 0;
}
