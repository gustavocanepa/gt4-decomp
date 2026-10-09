typedef unsigned int u32;

extern "C" void func_00603030();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088FDC0;

extern int D_0088FDB0;

extern "C" void *func_006030D0(void) {
    if (D_0088FDB0 == 0) {
        func_00603030();
        func_005BFB68(&D_0088FDB0, ((char *)"Q212GranTurismo421OptionRaceInputJaguar"), &D_0088FDC0);
    }
    return &D_0088FDB0;
}
