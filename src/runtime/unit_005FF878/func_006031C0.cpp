typedef unsigned int u32;

extern "C" void func_006023B0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088FCD0;

extern int D_0088FD90;

extern "C" void *func_006031C0(void) {
    if (D_0088FD90 == 0) {
        func_006023B0();
        func_005BFB68(&D_0088FD90, ((char *)"Q212GranTurismo423OptionRaceControllerPS2"), &D_0088FCD0);
    }
    return &D_0088FD90;
}
