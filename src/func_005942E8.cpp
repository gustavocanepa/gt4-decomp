extern "C" void func_005953D8();
extern "C" void func_005C1628(void *arg0);

extern "C" void func_005942E8(void *arg0, int arg1) {
    func_005953D8();
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
