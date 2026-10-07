typedef unsigned int u32;

extern "C" void func_005F52A0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069FA60[];
extern int D_0088F090;

static int D_0088D9A0;

extern "C" void *func_005F54E0(void) {
    if (D_0088D9A0 == 0) {
        func_005F52A0();
        func_005BFB68(&D_0088D9A0, D_0069FA60, &D_0088F090);
    }
    return &D_0088D9A0;
}
