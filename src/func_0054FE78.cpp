typedef int s32;

struct S0054FE78 {
    char pad0[0x38];
    s32 unk38;
};

extern "C" void func_005ADCB0(s32 arg0);

extern "C" void func_0054FE78(S0054FE78 *arg0) {
    func_005ADCB0(arg0->unk38);
}
