extern "C" void func_0037DB88(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_0067ACB8;

extern "C" void func_0037E390(void *arg0, int arg1) {
    *(void **)arg0 = &D_0067ACB8;
    func_0037DB88(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
