typedef int s32;

extern "C" void func_00262038(void *arg0);
extern "C" void func_00267EF0(void *arg0, void *arg1);

extern "C" void func_00262668(void *arg0) {
    char buf[0x10];
    func_00262038(buf);
    func_00267EF0(arg0, buf);
}
