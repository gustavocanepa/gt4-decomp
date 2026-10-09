typedef unsigned int u32;

extern "C" void func_005DAAE8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5EC0;

extern int D_0088E1A0;

extern "C" void *func_005DAB28(void) {
    if (D_0088E1A0 == 0) {
        func_005DAAE8();
        func_005BFB68(&D_0088E1A0, ((char *)"Q26PDISTDt15MTBufferedFifoT2Zci_256_"), &D_006D5EC0);
    }
    return &D_0088E1A0;
}
