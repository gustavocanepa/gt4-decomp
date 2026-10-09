extern "C" void MReaderBase__structor_0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *MRectangleReader__vtable;

extern "C" void MRectangleReader__structor_1(void *arg0, int arg1) {
    *(void **)arg0 = &MRectangleReader__vtable;
    MReaderBase__structor_0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
