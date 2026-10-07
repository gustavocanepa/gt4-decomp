typedef unsigned int u32;

extern "C" void func_00613DD8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00693D10[];
extern int D_006D62D8;

static int D_0088D9A0;

extern "C" void *func_005D0AC0(void) {
    if (D_0088D9A0 == 0) {
        func_00613DD8();
        func_005BFB68(&D_0088D9A0, D_00693D10, &D_006D62D8);
    }
    return &D_0088D9A0;
}
