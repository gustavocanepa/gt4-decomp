typedef unsigned int u32;

extern "C" void func_005F4E28();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F548[];
extern int D_006D5F80;

extern int D_0088F070;

extern "C" void *func_005F4D18(void) {
    if (D_0088F070 == 0) {
        func_005F4E28();
        func_005BFB68(&D_0088F070, D_0069F548, &D_006D5F80);
    }
    return &D_0088F070;
}
