typedef unsigned int u32;

extern "C" void func_00602780();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D60B0;

extern int D_0088FDF0;

extern "C" void *func_006032E0(void) {
    if (D_0088FDF0 == 0) {
        func_00602780();
        func_005BFB68(&D_0088FDF0, ((char *)"Q213SPEC_DATABASE9CarGarage"), &D_006D60B0);
    }
    return &D_0088FDF0;
}
