typedef unsigned int u32;

extern "C" void func_005DB158();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00698850[];
extern int D_006D5EC8;

static int D_0088D9A0;

extern "C" void *func_005DB568(void) {
    if (D_0088D9A0 == 0) {
        func_005DB158();
        func_005BFB68(&D_0088D9A0, D_00698850, &D_006D5EC8);
    }
    return &D_0088D9A0;
}
