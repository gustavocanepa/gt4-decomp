typedef unsigned int u32;

extern "C" void func_00611898();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C8AA8[];
extern int D_006D6260;

static int D_0088D9A0;

extern "C" void *func_00611948(void) {
    if (D_0088D9A0 == 0) {
        func_00611898();
        func_005BFB68(&D_0088D9A0, D_006C8AA8, &D_006D6260);
    }
    return &D_0088D9A0;
}
