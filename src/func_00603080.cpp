typedef unsigned int u32;

extern "C" void func_00603030();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A66B0[];
extern int D_0088FDC0;

static int D_0088D9A0;

extern "C" void *func_00603080(void) {
    if (D_0088D9A0 == 0) {
        func_00603030();
        func_005BFB68(&D_0088D9A0, D_006A66B0, &D_0088FDC0);
    }
    return &D_0088D9A0;
}
