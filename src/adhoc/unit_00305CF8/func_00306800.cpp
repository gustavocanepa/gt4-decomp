extern "C" void func_003065F0(int arg0, void *arg1);
extern "C" void func_00311790(void *arg0, int arg1);
extern "C" void func_00311B90(void *arg0);

extern "C" void func_00306800(int arg0) {
    char buf[8];
    func_00311B90(buf);
    func_003065F0(arg0, buf);
    func_00311790(buf, 2);
}
