extern "C" void MReaderBase__structor_0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *MWidgetReader__vtable;

extern "C" void MWidgetReader__structor_4(void *arg0, int arg1) {
    *(void **)arg0 = &MWidgetReader__vtable;
    MReaderBase__structor_0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
