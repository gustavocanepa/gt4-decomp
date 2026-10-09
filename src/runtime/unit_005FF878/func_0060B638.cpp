typedef unsigned int u32;

extern "C" void func_00612E68();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D62A8;

extern int D_008A0000;

extern "C" void *func_0060B638(void) {
    if (D_008A0000 == 0) {
        func_00612E68();
        func_005BFB68(&D_008A0000, ((char *)"Q26PDISTDt10UnitArenaT1Ui_16_"), &D_006D62A8);
    }
    return &D_008A0000;
}
