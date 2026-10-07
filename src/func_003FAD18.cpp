typedef int s32;

struct S003FAD18 {
    s32 unk0;
};

extern "C" void func_003FABA0(S003FAD18 *arg0, s32 arg1, s32 arg2);

extern "C" void func_003FAD18(S003FAD18 *arg0) {
    func_003FABA0(arg0, arg0->unk0, 0);
}
