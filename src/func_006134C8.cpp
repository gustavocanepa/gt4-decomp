typedef unsigned int u32;

extern "C" void func_00613C38();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006CC6D0[];
extern int D_006D62D0;

static int D_0088D9A0;

extern "C" void *func_006134C8(void) {
    if (D_0088D9A0 == 0) {
        func_00613C38();
        func_005BFB68(&D_0088D9A0, D_006CC6D0, &D_006D62D0);
    }
    return &D_0088D9A0;
}
