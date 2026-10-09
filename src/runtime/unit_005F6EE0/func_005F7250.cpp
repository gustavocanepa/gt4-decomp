typedef unsigned int u32;

extern "C" void func_00604AB0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A0350[];
extern int D_006D6110;

extern int D_0088F300;

extern "C" void *func_005F7250(void) {
    if (D_0088F300 == 0) {
        func_00604AB0();
        func_005BFB68(&D_0088F300, D_006A0350, &D_006D6110);
    }
    return &D_0088F300;
}
