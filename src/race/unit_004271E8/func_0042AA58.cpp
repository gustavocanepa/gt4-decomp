extern "C" void func_0042C9D8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00686BA0;

struct func_0042AA58_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void func_0042AA58(struct func_0042AA58_arg0 *arg0, int arg1) {
    arg0->unk4 = &D_00686BA0;
    func_0042C9D8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
