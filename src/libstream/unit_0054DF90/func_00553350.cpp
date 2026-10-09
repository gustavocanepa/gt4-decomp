typedef int s32;

extern "C" void func_005659F8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006898F8;

extern "C" void func_00553350(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x68) = &D_006898F8;
    func_005659F8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
