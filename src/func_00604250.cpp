typedef unsigned int u32;

extern "C" void func_00604AB0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006AAA68[];
extern int D_006D6110;

extern int D_0088FE50;

extern "C" void *func_00604250(void) {
    if (D_0088FE50 == 0) {
        func_00604AB0();
        func_005BFB68(&D_0088FE50, D_006AAA68, &D_006D6110);
    }
    return &D_0088FE50;
}
