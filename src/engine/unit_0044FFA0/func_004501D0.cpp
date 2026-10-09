typedef int s32;

struct Elem {
    char pad[0x10];
    s32 unk10;
};

extern "C" s32 func_004501D0(s32 arg0, s32 arg1) {
    s32 v = ((Elem *)(arg1 * 4 + arg0))->unk10;
    return arg0 + v + 2;
}
