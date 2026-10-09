typedef unsigned int u32;
typedef int s32;
typedef signed char s8;

struct Obj {
    char pad[0x26];
    s8 unk26;
};

extern "C" void func_0043CBF8(s32 arg0, u32 arg1, s32 arg2) {
    if (arg1 < 3U) {
        ((Obj *)(arg1 + arg0))->unk26 = arg2;
    }
}
