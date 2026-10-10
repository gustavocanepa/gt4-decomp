extern "C" void func_00577910(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00689E30;

struct func_00577E38_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void func_00577E38(struct func_00577E38_arg0 *arg0, int arg1) {
    arg0->unk4 = &D_00689E30;
    func_00577910(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
