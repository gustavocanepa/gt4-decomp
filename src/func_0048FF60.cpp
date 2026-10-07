typedef int s32;

struct S0048FF60 {
    char pad0[8];
    s32 unk8;
};

extern "C" void func_0048FD08(struct S0048FF60 *arg0, s32 arg1);

extern "C" void func_0048FF60(struct S0048FF60 *arg0) {
    func_0048FD08(arg0, arg0->unk8 - 1);
}
