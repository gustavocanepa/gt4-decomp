extern "C" void func_00575DA0(int arg0);
extern "C" void func_001CC060(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006611F0;
extern void *D_006614F8;

extern "C" void func_005D2250(void *arg0, int arg1) {
    int temp_v1;

    *(void **)((char *)arg0 + 0x4C) = &D_006611F0;
    temp_v1 = *(int *)((char *)arg0 + 0x54);
    if (temp_v1 != 0) {
        func_00575DA0(temp_v1);
    }
    *(void **)((char *)arg0 + 0x4C) = &D_006614F8;
    func_001CC060(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
