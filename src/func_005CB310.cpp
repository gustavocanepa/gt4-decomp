typedef unsigned int u32;

extern "C" void func_005D8418();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00690CF0[];
extern int D_0088E0B0;

static int D_0088D9A0;

extern "C" void *func_005CB310(void) {
    if (D_0088D9A0 == 0) {
        func_005D8418();
        func_005BFB68(&D_0088D9A0, D_00690CF0, &D_0088E0B0);
    }
    return &D_0088D9A0;
}
