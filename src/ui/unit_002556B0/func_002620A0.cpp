typedef int s32;

extern "C" void MVectorReader__structor_0(void *arg0);
extern "C" void func_0024DB78(void *arg0, s32 arg1);
extern "C" void MVectorReader__structor_1(void *arg0, s32 arg1);

extern "C" void func_002620A0(s32 arg0) {
    char buf[8];
    MVectorReader__structor_0(buf);
    func_0024DB78(buf, arg0);
    MVectorReader__structor_1(buf, 2);
}
