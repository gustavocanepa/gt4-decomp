typedef int s32;

extern "C" void func_0057CA38(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006897A0;

struct func_0060F9E8_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_0060F9E8(struct func_0060F9E8_arg0 *arg0, s32 arg1) {
    arg0->unk8 = &D_006897A0;
    func_0057CA38(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
