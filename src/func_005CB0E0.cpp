typedef unsigned int u32;

extern "C" void func_005CB130();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00690B78[];
extern int D_006D5E60;

extern int D_0088DBF0;

extern "C" void *func_005CB0E0(void) {
    if (D_0088DBF0 == 0) {
        func_005CB130();
        func_005BFB68(&D_0088DBF0, D_00690B78, &D_006D5E60);
    }
    return &D_0088DBF0;
}
