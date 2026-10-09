extern "C" void func_003065F0(int arg0, void *arg1);
extern "C" void func_0032BA00(void *arg0, int arg1);
extern "C" void func_0032BD38(void *arg0);

extern "C" void func_002F3790(int arg0) {
    char buf[8];
    func_0032BD38(buf);
    func_003065F0(arg0, buf);
    func_0032BA00(buf, 2);
}
