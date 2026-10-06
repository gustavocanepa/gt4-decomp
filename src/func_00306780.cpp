extern "C" void func_003065F0(int arg0, void *arg1);
extern "C" void func_0032CF10(void *arg0, int arg1);
extern "C" void func_0032D218(void *arg0);

extern "C" void func_00306780(int arg0) {
    char buf[8];
    func_0032D218(buf);
    func_003065F0(arg0, buf);
    func_0032CF10(buf, 2);
}
