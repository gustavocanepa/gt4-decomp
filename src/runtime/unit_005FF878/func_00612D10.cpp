typedef unsigned int u32;

extern "C" void func_00612CD0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D62A0;

extern int D_008A1B40;

extern "C" void *func_00612D10(void) {
    if (D_008A1B40 == 0) {
        func_00612CD0();
        func_005BFB68(&D_008A1B40, ((char *)"Q26PDISTD12InflatorBase"), &D_006D62A0);
    }
    return &D_008A1B40;
}
