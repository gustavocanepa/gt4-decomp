typedef int s32;

struct S { char pad[0x1B]; unsigned char flag; };

extern "C" s32 func_00463E98(S *arg0) {
    return arg0->flag != 0;
}
