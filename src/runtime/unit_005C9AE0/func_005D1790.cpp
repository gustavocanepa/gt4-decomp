extern "C" void func_00575DA0(int arg0);
extern "C" void func_001CC060(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006611F0;
extern void *D_006614F8;

struct func_005D1790_arg0 {
    char pad0[0x4C];
    void *unk4C;
    char pad50[0x4];
    int unk54;
};

extern "C" void func_005D1790(struct func_005D1790_arg0 *arg0, int arg1) {
    int temp_v1;

    arg0->unk4C = &D_006611F0;
    temp_v1 = arg0->unk54;
    if (temp_v1 != 0) {
        func_00575DA0(temp_v1);
    }
    arg0->unk4C = &D_006614F8;
    func_001CC060(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
