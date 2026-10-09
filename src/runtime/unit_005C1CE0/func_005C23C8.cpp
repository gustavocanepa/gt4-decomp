typedef unsigned int u32;

extern "C" void func_005C1F98();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068CD20[];
extern int D_0088D960;

extern int D_0088DA30;

extern "C" void *func_005C23C8(void) {
    if (D_0088DA30 == 0) {
        func_005C1F98();
        func_005BFB68(&D_0088DA30, D_0068CD20, &D_0088D960);
    }
    return &D_0088DA30;
}
