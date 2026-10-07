extern "C" void func_003065F0(int arg0, void *arg1);
extern "C" void func_0032D9A0(void *arg0, int arg1);
extern "C" void func_0032DCC0(void *arg0);

extern "C" void func_002F36E0(int arg0) {
    char buf[8];
    func_0032DCC0(buf);
    func_003065F0(arg0, buf);
    func_0032D9A0(buf, 2);
}
