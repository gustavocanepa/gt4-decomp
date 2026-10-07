extern "C" void func_00101078(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_0067E140;

extern "C" void func_005F7130(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x64) = &D_0067E140;
    func_00101078(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
