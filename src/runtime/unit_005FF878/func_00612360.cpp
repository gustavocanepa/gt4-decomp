typedef unsigned int u32;

extern "C" void func_00613DD8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D62D8;

extern int D_008A1AC0;

extern "C" void *func_00612360(void) {
    if (D_008A1AC0 == 0) {
        func_00613DD8();
        func_005BFB68(&D_008A1AC0, ((char *)"Q26PDISTDt12ListManagerT1ZQ26PDISTD11ControlBase"), &D_006D62D8);
    }
    return &D_008A1AC0;
}
