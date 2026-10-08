typedef unsigned int u32;
typedef int s32;
typedef signed char s8;

struct Obj {
    char pad[0x11];
    s8 unk11;
};

extern "C" s32 func_0043C0B8(s32 arg0, u32 arg1) {
    if (arg1 < 0xCU) {
        return ((Obj *)(arg1 + arg0))->unk11;
    }
    return -1;
}
