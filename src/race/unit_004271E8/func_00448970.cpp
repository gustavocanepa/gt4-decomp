typedef int s32;

struct S { char pad[0x16]; unsigned char flag; };

extern "C" s32 func_00448970(S *arg0) {
    return arg0->flag != 0;
}
