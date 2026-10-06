extern "C" void func_003065F0(int arg0, void *arg1);
extern "C" void func_00310BF0(void *arg0, int arg1);
extern "C" void func_00310FF0(void *arg0);

extern "C" void func_002F36A0(int arg0) {
    char buf[8];
    func_00310FF0(buf);
    func_003065F0(arg0, buf);
    func_00310BF0(buf, 2);
}
