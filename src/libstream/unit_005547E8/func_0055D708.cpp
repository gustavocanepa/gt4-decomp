extern "C" {
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0055C648(...) throw();
s32 func_0055D778(...) throw();

struct func_0055D708_arg0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x10];
    u8 unk1C;
    char pad1D[0x13];
    s32 unk30;
};

void func_0055D708(char *arg0, s32 arg1) {
    func_0055C648(((struct func_0055D708_arg0 *)arg0)->unk8, arg0, arg1 == 0);
    if (((struct func_0055D708_arg0 *)arg0)->unk1C != 0) {
        func_0055D778(arg0, ((struct func_0055D708_arg0 *)arg0)->unk30);
        return;
    }
    func_0055D778(arg0, arg1);
}

}
