typedef int s32;

extern void *streambuf__vtable;
extern "C" void func_00595008(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void streambuf__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x50) = &streambuf__vtable;
    func_00595008(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
