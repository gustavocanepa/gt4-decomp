typedef int s32;

extern "C" void func_00262038(void *arg0);
extern "C" void func_002681A8(void *arg0, void *arg1);

extern "C" void func_002626A0(void *arg0) {
    char buf[0x10];
    func_00262038(buf);
    func_002681A8(arg0, buf);
}
