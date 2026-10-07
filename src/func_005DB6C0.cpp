typedef unsigned int u32;

extern "C" void func_005DA320();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00698860[];
extern int D_006D5EB8;

static int D_0088D9A0;

extern "C" void *func_005DB6C0(void) {
    if (D_0088D9A0 == 0) {
        func_005DA320();
        func_005BFB68(&D_0088D9A0, D_00698860, &D_006D5EB8);
    }
    return &D_0088D9A0;
}
