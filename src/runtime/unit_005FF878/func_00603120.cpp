typedef unsigned int u32;

extern "C" void func_00603030();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088FDC0;

extern int D_0088FDD0;

extern "C" void *func_00603120(void) {
    if (D_0088FDD0 == 0) {
        func_00603030();
        func_005BFB68(&D_0088FDD0, ((char *)"Q212GranTurismo422OptionRaceInputCheetah"), &D_0088FDC0);
    }
    return &D_0088FDD0;
}
