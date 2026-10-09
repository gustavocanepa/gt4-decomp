extern "C" void MReaderBase__structor_0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00669E18;

extern "C" void func_005E5090(void *arg0, int arg1) {
    *(void **)arg0 = &D_00669E18;
    MReaderBase__structor_0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
