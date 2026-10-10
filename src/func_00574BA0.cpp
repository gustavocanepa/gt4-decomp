extern "C" void func_00572CF8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00689D40;

struct func_00574BA0_arg0 {
    char pad0[0x44];
    void *unk44;
};

extern "C" void func_00574BA0(struct func_00574BA0_arg0 *arg0, int arg1) {
    arg0->unk44 = &D_00689D40;
    func_00572CF8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
