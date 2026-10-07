typedef unsigned int u32;

extern "C" void func_00604FF0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00693E50[];
extern int D_006D6138;

static int D_0088D9A0;

extern "C" void *func_005D0D60(void) {
    if (D_0088D9A0 == 0) {
        func_00604FF0();
        func_005BFB68(&D_0088D9A0, D_00693E50, &D_006D6138);
    }
    return &D_0088D9A0;
}
