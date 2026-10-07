typedef unsigned int u32;

extern "C" void func_005F52A0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A2D80[];
extern int D_0088F090;

extern int D_0088F7F0;

extern "C" void *func_005FD9A0(void) {
    if (D_0088F7F0 == 0) {
        func_005F52A0();
        func_005BFB68(&D_0088F7F0, D_006A2D80, &D_0088F090);
    }
    return &D_0088F7F0;
}
