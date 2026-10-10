extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00576AD8(...) throw();
s32 func_00576B28(...) throw();
s32 func_00578168(...) throw();
s32 func_00578500(...) throw();

struct func_00550C68_arg0 {
    s32 unk0;
    char pad4[0x3C];
    s32 unk40;
    s32 unk44;
    s32 unk48;
};

void func_00550C68(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_00578500(((struct func_00550C68_arg0 *)arg0)->unk0);
    ((struct func_00550C68_arg0 *)arg0)->unk40 = arg2;
    ((struct func_00550C68_arg0 *)arg0)->unk44 = arg3;
    ((struct func_00550C68_arg0 *)arg0)->unk48 = arg4;
    func_00576AD8(arg3, arg4);
    func_00578168(arg0, arg1, 0, 0, 0);
    func_00576B28(arg3, arg4);
}

}
