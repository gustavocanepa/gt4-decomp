typedef unsigned int u32;

extern "C" void func_005E5760();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006978A0[];
extern int D_0088E5D0;

extern int D_0088E0D0;

extern "C" void *func_005D8AC8(void) {
    if (D_0088E0D0 == 0) {
        func_005E5760();
        func_005BFB68(&D_0088E0D0, D_006978A0, &D_0088E5D0);
    }
    return &D_0088E0D0;
}
