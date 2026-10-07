typedef unsigned int u32;

extern "C" void func_005D15A8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00695010[];
extern int D_0088DEB0;

extern int D_0088DE90;

extern "C" void *func_005D1818(void) {
    if (D_0088DE90 == 0) {
        func_005D15A8();
        func_005BFB68(&D_0088DE90, D_00695010, &D_0088DEB0);
    }
    return &D_0088DE90;
}
