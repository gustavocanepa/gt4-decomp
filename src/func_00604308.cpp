typedef unsigned int u32;

extern "C" void func_00604AB0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006AAA88[];
extern int D_006D6110;

static int D_0088D9A0;

extern "C" void *func_00604308(void) {
    if (D_0088D9A0 == 0) {
        func_00604AB0();
        func_005BFB68(&D_0088D9A0, D_006AAA88, &D_006D6110);
    }
    return &D_0088D9A0;
}
