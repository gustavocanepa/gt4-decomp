typedef unsigned int u32;

extern "C" void func_005DA190();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697D78[];
extern int D_006D5EB0;

static int D_0088D9A0;

extern "C" void *func_005DA208(void) {
    if (D_0088D9A0 == 0) {
        func_005DA190();
        func_005BFB68(&D_0088D9A0, D_00697D78, &D_006D5EB0);
    }
    return &D_0088D9A0;
}
