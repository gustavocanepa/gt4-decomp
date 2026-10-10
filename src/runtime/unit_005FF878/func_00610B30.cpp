typedef int s32;

extern "C" void func_0057CA38(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00689890;

struct func_00610B30_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_00610B30(struct func_00610B30_arg0 *arg0, s32 arg1) {
    arg0->unk8 = &D_00689890;
    func_0057CA38(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
