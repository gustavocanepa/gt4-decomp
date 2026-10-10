#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
void func_00458D40(s32);
void func_00458DA8(s32, s32, s32);
struct func_00450C48_arg0 {
    s32 unk0;
    char pad4[0x5B4];
    s32 unk5B8;
};

void func_00450C48(struct func_00450C48_arg0 *arg0) {
    s32 temp_v0;
    temp_v0 = arg0->unk5B8;
    if (temp_v0 != 0) {
        return func_00458DA8(arg0->unk0, temp_v0, 0);
    }
    func_00458D40(arg0->unk0);
}

}
