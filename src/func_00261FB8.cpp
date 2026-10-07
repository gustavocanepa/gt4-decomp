typedef int s32;

extern "C" void func_0022A840(void *arg0);
extern "C" void func_0024DB78(void *arg0, s32 arg1);
extern "C" void func_0022A858(void *arg0, s32 arg1);

extern "C" void func_00261FB8(s32 arg0) {
    char buf[8];
    func_0022A840(buf);
    func_0024DB78(buf, arg0);
    func_0022A858(buf, 2);
}
