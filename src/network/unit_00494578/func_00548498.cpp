extern "C" void func_00578090(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006897D8;

struct func_00548498_arg0 {
    char pad0[0x38];
    void *unk38;
};

extern "C" void func_00548498(struct func_00548498_arg0 *arg0, int arg1) {
    arg0->unk38 = &D_006897D8;
    func_00578090(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
