typedef unsigned int u32;

extern "C" void func_0060F650();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6220;

extern int D_008A00F0;

extern "C" void *func_0060F690(void) {
    if (D_008A00F0 == 0) {
        func_0060F650();
        func_005BFB68(&D_008A00F0, ((char *)"Q26PDISTDt15CSBufferedFifoT2ZQ27PDICOMM14CommNodePacketi8"), &D_006D6220);
    }
    return &D_008A00F0;
}
