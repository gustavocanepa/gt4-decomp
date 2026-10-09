typedef unsigned int u32;

extern "C" void func_00602300();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D60A8;

extern int D_0088FD80;

extern "C" void *func_00602FE0(void) {
    if (D_0088FD80 == 0) {
        func_00602300();
        func_005BFB68(&D_0088FD80, ((char *)"Q212GranTurismo425OptionRaceInputDualShock2"), &D_006D60A8);
    }
    return &D_0088FD80;
}
