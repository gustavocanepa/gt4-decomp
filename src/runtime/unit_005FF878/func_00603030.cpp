typedef unsigned int u32;

extern "C" void func_00602300();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D60A8;

extern int D_0088FDC0;

extern "C" void *func_00603030(void) {
    if (D_0088FDC0 == 0) {
        func_00602300();
        func_005BFB68(&D_0088FDC0, ((char *)"Q212GranTurismo422OptionRaceInputGTForce"), &D_006D60A8);
    }
    return &D_0088FDC0;
}
