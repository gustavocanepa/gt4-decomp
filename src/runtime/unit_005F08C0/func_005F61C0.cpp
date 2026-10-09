typedef unsigned int u32;

extern "C" void func_005F5550();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069FCB8[];
extern int D_0088F0B0;

extern int D_0088F190;

extern "C" void *func_005F61C0(void) {
    if (D_0088F190 == 0) {
        func_005F5550();
        func_005BFB68(&D_0088F190, D_0069FCB8, &D_0088F0B0);
    }
    return &D_0088F190;
}
