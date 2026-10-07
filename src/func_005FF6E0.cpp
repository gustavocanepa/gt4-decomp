typedef unsigned int u32;

extern "C" void func_005FF5F0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A47B0[];
extern int D_006D6080;

static int D_0088D9A0;

extern "C" void *func_005FF6E0(void) {
    if (D_0088D9A0 == 0) {
        func_005FF5F0();
        func_005BFB68(&D_0088D9A0, D_006A47B0, &D_006D6080);
    }
    return &D_0088D9A0;
}
