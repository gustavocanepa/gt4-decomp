typedef unsigned int u32;
typedef int s32;
typedef signed char s8;

struct Obj {
    char pad[0x10];
    s8 unk10;
    char pad2[0x1D - 0x10 - 1];
    s8 unk1D;
};

extern "C" void func_0043C120(s32 arg0, u32 arg1, s32 arg2) {
    if (arg1 < 0x10U) {
        ((Obj *)arg0)->unk10 = 0;
        ((Obj *)(arg1 + arg0))->unk1D = arg2;
    }
}
