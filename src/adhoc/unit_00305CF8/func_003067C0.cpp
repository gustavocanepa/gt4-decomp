extern "C" void func_003065F0(int arg0, void *arg1);
extern "C" void func_00310028(void *arg0, int arg1);
extern "C" void func_00310468(void *arg0);

extern "C" void func_003067C0(int arg0) {
    char buf[8];
    func_00310468(buf);
    func_003065F0(arg0, buf);
    func_00310028(buf, 2);
}
