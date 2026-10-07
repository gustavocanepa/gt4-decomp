typedef unsigned int u32;

extern "C" void func_005FF068();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A40F8[];
extern int D_0088FA20;

static int D_0088D9A0;

extern "C" void *func_005FEFA8(void) {
    if (D_0088D9A0 == 0) {
        func_005FF068();
        func_005BFB68(&D_0088D9A0, D_006A40F8, &D_0088FA20);
    }
    return &D_0088D9A0;
}
