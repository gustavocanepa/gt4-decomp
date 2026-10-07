typedef unsigned int u32;

extern "C" void func_005FF5F0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A47E0[];
extern int D_006D6080;

extern int D_0088FAA0;

extern "C" void *func_005FF7F0(void) {
    if (D_0088FAA0 == 0) {
        func_005FF5F0();
        func_005BFB68(&D_0088FAA0, D_006A47E0, &D_006D6080);
    }
    return &D_0088FAA0;
}
