extern "C" void func_0043A408(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00659D90;

extern "C" void func_00438B18(void *arg0, int arg1) {
    *(void **)arg0 = &D_00659D90;
    func_0043A408(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
