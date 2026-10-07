typedef unsigned int u32;

extern "C" void func_005E6368();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069C858[];
extern int D_0088E6F0;

static int D_0088D9A0;

extern "C" void *func_005E9C80(void) {
    if (D_0088D9A0 == 0) {
        func_005E6368();
        func_005BFB68(&D_0088D9A0, D_0069C858, &D_0088E6F0);
    }
    return &D_0088D9A0;
}
