extern "C" void func_001CC060(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006614F8;

struct func_005D16D8_arg0 {
    char pad0[0x4C];
    void *unk4C;
};

extern "C" void func_005D16D8(struct func_005D16D8_arg0 *arg0, int arg1) {
    arg0->unk4C = &D_006614F8;
    func_001CC060(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
