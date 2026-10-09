typedef unsigned int u32;
typedef int s32;
typedef signed char s8;

struct Obj {
    char pad[0x1D];
    s8 unk1D;
};

extern "C" s32 func_0043C100(s32 arg0, u32 arg1) {
    if (arg1 < 0x10U) {
        return ((Obj *)(arg1 + arg0))->unk1D;
    }
    return -1;
}
