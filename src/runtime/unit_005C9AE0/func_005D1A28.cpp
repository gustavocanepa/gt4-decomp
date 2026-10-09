typedef unsigned int u32;

extern "C" void func_005D1950();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088DEF0;

extern int D_0088DEA0;

extern "C" void *func_005D1A28(void) {
    if (D_0088DEA0 == 0) {
        func_005D1950();
        func_005BFB68(&D_0088DEA0, ((char *)"Q25GT4MC17FileGT4ReplayFull"), &D_0088DEF0);
    }
    return &D_0088DEA0;
}
