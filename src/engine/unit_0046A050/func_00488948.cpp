typedef int s32;

extern "C" void func_004887D8(void *arg0);
extern "C" void func_0048D510(void *arg0, void *arg1);

extern "C" void func_00488948(void *arg0) {
    char buf[0x10];
    func_004887D8(buf);
    func_0048D510(arg0, buf);
}
