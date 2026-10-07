typedef int s32;

struct S { char pad[0x68]; unsigned char flag; };

extern "C" s32 func_00367D20(S *arg0) {
    return arg0->flag != 0;
}
