typedef int s32;

extern "C" void func_002CC648(void *arg0);
extern "C" void func_0024DB78(void *arg0, s32 arg1);
extern "C" void func_002CC660(void *arg0, s32 arg1);

extern "C" void func_00261FF8(s32 arg0) {
    char buf[8];
    func_002CC648(buf);
    func_0024DB78(buf, arg0);
    func_002CC660(buf, 2);
}
