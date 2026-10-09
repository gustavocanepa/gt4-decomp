typedef unsigned int u32;

extern "C" void func_00613C38();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D62D0;

extern int D_008A1B90;

extern "C" void *func_006134C8(void) {
    if (D_008A1B90 == 0) {
        func_00613C38();
        func_005BFB68(&D_008A1B90, ((char *)"Q26PDISTD10MTFifoBase"), &D_006D62D0);
    }
    return &D_008A1B90;
}
