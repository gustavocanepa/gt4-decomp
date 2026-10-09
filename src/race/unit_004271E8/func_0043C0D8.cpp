typedef unsigned int u32;
typedef int s32;
typedef signed char s8;

struct Obj {
    char pad[0x10];
    s8 unk10;
    s8 unk11;
};

extern "C" void func_0043C0D8(s32 arg0, u32 arg1, s32 arg2) {
    if (arg1 < 0xCU) {
        ((Obj *)arg0)->unk10 = 0;
        ((Obj *)(arg1 + arg0))->unk11 = arg2;
    }
}
