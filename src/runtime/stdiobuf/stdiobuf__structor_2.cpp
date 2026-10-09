typedef int s32;

extern void *stdiobuf__vtable;
extern "C" void func_0059B038(void *, void *, s32);
extern "C" void filebuf__structor_3(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void stdiobuf__structor_2(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x50) = &stdiobuf__vtable;
    func_0059B038(arg0, *(void **)((char *)arg0 + 0x10), ((s32)*(void **)((char *)arg0 + 0x14) - (s32)*(void **)((char *)arg0 + 0x10)));
    filebuf__structor_3(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
