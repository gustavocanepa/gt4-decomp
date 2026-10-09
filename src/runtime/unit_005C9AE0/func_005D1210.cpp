typedef unsigned int u32;

extern "C" void func_005CB708();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5E68;

extern int D_0088DEE0;

extern "C" void *func_005D1210(void) {
    if (D_0088DEE0 == 0) {
        func_005CB708();
        func_005BFB68(&D_0088DEE0, ((char *)"Q35GT4MC4File13ProgressProxy"), &D_006D5E68);
    }
    return &D_0088DEE0;
}
