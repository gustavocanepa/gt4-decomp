typedef unsigned int u32;
typedef int s32;
typedef signed char s8;

struct Obj {
    char pad[0x14];
    s8 unk14;
};

extern "C" s32 func_0043CB90(s32 arg0, u32 arg1) {
    if (arg1 < 0x12U) {
        return ((Obj *)(arg1 + arg0))->unk14;
    }
    return -1;
}
