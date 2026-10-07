typedef unsigned int u32;

extern "C" void func_005FDC20();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3148[];
extern int D_006D6038;

static int D_0088D9A0;

extern "C" void *func_005FDBB0(void) {
    if (D_0088D9A0 == 0) {
        func_005FDC20();
        func_005BFB68(&D_0088D9A0, D_006A3148, &D_006D6038);
    }
    return &D_0088D9A0;
}
