typedef unsigned int u32;

extern "C" void func_0060F6E0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6208;

extern int D_008A00D0;

extern "C" void *func_0060F720(void) {
    if (D_008A00D0 == 0) {
        func_0060F6E0();
        func_005BFB68(&D_008A00D0, ((char *)"Q26PDISTDt15CSBufferedFifoT2ZQ27PDICOMM14CommLeafPacketi4"), &D_006D6208);
    }
    return &D_008A00D0;
}
