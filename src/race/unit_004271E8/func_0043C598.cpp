typedef int s32;
typedef unsigned int u32;
typedef signed char s8;

struct Elem {
    char pad[0x14];
    s8 unk14;
};

extern "C" s32 func_0043C598(s32 arg0, u32 arg1) {
    if (arg1 < 6U) {
        return ((Elem *)(arg1 + arg0))->unk14;
    }
    return -1;
}
