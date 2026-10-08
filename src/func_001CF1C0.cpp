typedef int s32;

struct Pair {
    s32 unk0;
    s32 unk4;
};

extern "C" s32 func_001CCEC8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" s32 func_001CF1C0(s32 arg0, s32 arg1, struct Pair *arg2, s32 arg3) {
    return func_001CCEC8(arg0, arg1, arg2->unk0, arg2->unk4, arg3) == 0;
}
