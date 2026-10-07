typedef int s32;

extern "C" void func_00488B98(void *arg0);
extern "C" void func_0048D510(void *arg0, void *arg1);

extern "C" void func_00488DF0(void *arg0) {
    char buf[0x10];
    func_00488B98(buf);
    func_0048D510(arg0, buf);
}
