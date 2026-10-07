typedef int s32;

extern "C" void func_0057CA38(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00688C40;

extern "C" void func_0060A4B0(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x8) = &D_00688C40;
    func_0057CA38(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
