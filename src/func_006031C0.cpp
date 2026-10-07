typedef unsigned int u32;

extern "C" void func_006023B0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A6760[];
extern int D_0088FCD0;

static int D_0088D9A0;

extern "C" void *func_006031C0(void) {
    if (D_0088D9A0 == 0) {
        func_006023B0();
        func_005BFB68(&D_0088D9A0, D_006A6760, &D_0088FCD0);
    }
    return &D_0088D9A0;
}
