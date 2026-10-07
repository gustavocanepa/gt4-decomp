extern "C" void func_00377D20(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006820C8;

extern "C" void func_005FD650(void *arg0, int arg1) {
    *(void **)arg0 = &D_006820C8;
    func_00377D20(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
