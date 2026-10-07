typedef unsigned int u32;

extern "C" void func_005FAF28();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F3C0[];
extern int D_006D5FE8;

extern int D_0088F040;

extern "C" void *func_005F39A8(void) {
    if (D_0088F040 == 0) {
        func_005FAF28();
        func_005BFB68(&D_0088F040, D_0069F3C0, &D_006D5FE8);
    }
    return &D_0088F040;
}
