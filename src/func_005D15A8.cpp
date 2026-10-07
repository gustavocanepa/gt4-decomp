typedef unsigned int u32;

extern "C" void func_005D1260();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00694FB8[];
extern int D_006D5E98;

extern int D_0088DEB0;

extern "C" void *func_005D15A8(void) {
    if (D_0088DEB0 == 0) {
        func_005D1260();
        func_005BFB68(&D_0088DEB0, D_00694FB8, &D_006D5E98);
    }
    return &D_0088DEB0;
}
