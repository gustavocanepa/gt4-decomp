typedef int s32;
typedef unsigned int u32;
typedef char s8;

struct Elem {
    char pad[0x11];
    s8 unk11;
};

extern "C" s32 func_0043C838(s32 arg0, u32 arg1) {
    if (arg1 < 3U) {
        return ((Elem *)(arg1 + arg0))->unk11;
    }
    return -1;
}
