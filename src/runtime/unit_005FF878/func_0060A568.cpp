typedef unsigned int u32;

extern "C" void func_0060A750();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B00B0[];
extern int D_006D61A0;

extern int D_0088FEF8;

extern "C" void *func_0060A568(void) {
    if (D_0088FEF8 == 0) {
        func_0060A750();
        func_005BFB68(&D_0088FEF8, D_006B00B0, &D_006D61A0);
    }
    return &D_0088FEF8;
}
