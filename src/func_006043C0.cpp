typedef unsigned int u32;

extern "C" void func_00604AB0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006AAAB0[];
extern int D_006D6110;

extern int D_0088FE60;

extern "C" void *func_006043C0(void) {
    if (D_0088FE60 == 0) {
        func_00604AB0();
        func_005BFB68(&D_0088FE60, D_006AAAB0, &D_006D6110);
    }
    return &D_0088FE60;
}
