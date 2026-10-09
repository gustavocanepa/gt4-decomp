typedef int s32;

struct Pair {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_0055D548(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_0055CE88(s32 arg0, struct Pair *arg1) {
    func_0055D548(arg0, arg1->unk0, arg1->unk4);
}
