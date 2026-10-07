typedef unsigned int u32;

extern "C" void func_005E5760();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697DD8[];
extern int D_0088E5D0;

static int D_0088D9A0;

extern "C" void *func_005DA378(void) {
    if (D_0088D9A0 == 0) {
        func_005E5760();
        func_005BFB68(&D_0088D9A0, D_00697DD8, &D_0088E5D0);
    }
    return &D_0088D9A0;
}
