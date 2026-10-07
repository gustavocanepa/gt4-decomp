typedef unsigned int u32;

extern "C" void func_00600610();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A4DD8[];
extern int D_0088FBC0;

static int D_0088D9A0;

extern "C" void *func_006006B0(void) {
    if (D_0088D9A0 == 0) {
        func_00600610();
        func_005BFB68(&D_0088D9A0, D_006A4DD8, &D_0088FBC0);
    }
    return &D_0088D9A0;
}
