extern "C" void func_001D5140();
extern "C" void func_005C1628(void *arg0);

extern "C" void func_001D5020(void *arg0, int arg1) {
    func_001D5140();
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
