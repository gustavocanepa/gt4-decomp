typedef int s32;

extern "C" void func_00253C08(void *arg0);
extern "C" void func_0024DB78(void *arg0, s32 arg1);
extern "C" void func_00253C20(void *arg0, s32 arg1);

extern "C" void func_002620A0(s32 arg0) {
    char buf[8];
    func_00253C08(buf);
    func_0024DB78(buf, arg0);
    func_00253C20(buf, 2);
}
