extern "C" {
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004A0910(...) throw();
s32 func_004A0B78(...) throw();
s32 func_004A0C10(...) throw();

struct func_00105608_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    char pad20[0x10];
    s32 unk30;
};

void func_00105608(char *arg0) {
    if (((struct func_00105608_arg0 *)arg0)->unk30 != 0) {
        func_004A0B78(((struct func_00105608_arg0 *)arg0)->unk10, ((struct func_00105608_arg0 *)arg0)->unk14, ((struct func_00105608_arg0 *)arg0)->unk18, ((struct func_00105608_arg0 *)arg0)->unk1C);
        func_004A0C10(((struct func_00105608_arg0 *)arg0)->unk0, ((struct func_00105608_arg0 *)arg0)->unk4, ((struct func_00105608_arg0 *)arg0)->unk8, ((struct func_00105608_arg0 *)arg0)->unkC);
        return;
    }
    func_004A0910(0);
}

}
