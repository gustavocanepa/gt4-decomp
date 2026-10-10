#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
void func_004AA6B8(s32); void func_00575DA0(s32) throw();
struct func_00107B98_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char padC[0x4];
    s32 unk10;
};

void func_00107B98(struct func_00107B98_arg0 *arg0) {
    func_004AA6B8(arg0->unk0);
    if (arg0->unk10 != 0) {
        func_00575DA0(arg0->unk8);
    }
    arg0->unk10 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unk0 = -1;
}

}
