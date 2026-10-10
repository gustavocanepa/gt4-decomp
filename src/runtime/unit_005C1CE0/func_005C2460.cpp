typedef int s32;

extern "C" void func_00578F48(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00659B88;

struct func_005C2460_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_005C2460(struct func_005C2460_arg0 *arg0, s32 arg1) {
    arg0->unk8 = &D_00659B88;
    func_00578F48(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
