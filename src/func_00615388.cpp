typedef unsigned int u32;

extern "C" void func_00615BD8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006CF880[];
extern int D_006D62F0;

static int D_0088D9A0;

extern "C" void *func_00615388(void) {
    if (D_0088D9A0 == 0) {
        func_00615BD8();
        func_005BFB68(&D_0088D9A0, D_006CF880, &D_006D62F0);
    }
    return &D_0088D9A0;
}
