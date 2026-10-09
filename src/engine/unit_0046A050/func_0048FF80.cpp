typedef int s32;

struct S0048FF60 {
    char pad0[8];
    s32 unk8;
};

extern "C" void func_00490090(struct S0048FF60 *arg0, s32 arg1);

extern "C" void func_0048FF80(struct S0048FF60 *arg0) {
    func_00490090(arg0, arg0->unk8 - 1);
}
