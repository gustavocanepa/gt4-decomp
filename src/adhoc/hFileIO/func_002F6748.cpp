extern "C" void func_002FEAB0(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_002F6748(void *arg0, int arg1) {
    func_002FEAB0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
