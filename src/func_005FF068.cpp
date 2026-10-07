typedef unsigned int u32;

extern "C" void func_005FEE28();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A4118[];
extern int D_0088F9F0;

static int D_0088D9A0;

extern "C" void *func_005FF068(void) {
    if (D_0088D9A0 == 0) {
        func_005FEE28();
        func_005BFB68(&D_0088D9A0, D_006A4118, &D_0088F9F0);
    }
    return &D_0088D9A0;
}
