extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0047FEC0(...) throw();
void func_00480100(...) throw();
s32 func_004816F8(...) throw();

struct func_0047FC78_arg0 {
    char pad0[0x6C];
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
};

void func_0047FC78(char *arg0, s32 arg1) {
    func_004816F8(arg0 + 0x8C, arg0);
    ((struct func_0047FC78_arg0 *)arg0)->unk6C = 0;
    ((struct func_0047FC78_arg0 *)arg0)->unk74 = 1;
    ((struct func_0047FC78_arg0 *)arg0)->unk70 = 0;
    ((struct func_0047FC78_arg0 *)arg0)->unk78 = 0;
    func_00480100(arg0, arg1);
    func_0047FEC0(arg0, arg1);
}

}
