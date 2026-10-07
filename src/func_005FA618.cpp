typedef unsigned int u32;

extern "C" void func_005F8408();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1C70[];
extern int D_0088F660;

static int D_0088D9A0;

extern "C" void *func_005FA618(void) {
    if (D_0088D9A0 == 0) {
        func_005F8408();
        func_005BFB68(&D_0088D9A0, D_006A1C70, &D_0088F660);
    }
    return &D_0088D9A0;
}
