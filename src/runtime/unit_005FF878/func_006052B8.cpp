typedef int s32;

struct Obj {
    char pad[0x734];
    s32 unk734;
};

extern "C" s32 func_006052B8(char *arg0, s32 arg1, s32 arg2) {
    return ((Obj *)(arg1 * 4 + arg0))->unk734 + (arg2 << 8);
}
