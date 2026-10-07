typedef unsigned int u32;

extern "C" void func_005F6C50();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F3D0[];
extern int D_006D5FA0;

static int D_0088D9A0;

extern "C" void *func_005F39F8(void) {
    if (D_0088D9A0 == 0) {
        func_005F6C50();
        func_005BFB68(&D_0088D9A0, D_0069F3D0, &D_006D5FA0);
    }
    return &D_0088D9A0;
}
