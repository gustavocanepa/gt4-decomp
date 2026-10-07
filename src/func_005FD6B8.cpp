typedef unsigned int u32;

extern "C" void func_005F54E0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A2D28[];
extern int D_0088F0A0;

static int D_0088D9A0;

extern "C" void *func_005FD6B8(void) {
    if (D_0088D9A0 == 0) {
        func_005F54E0();
        func_005BFB68(&D_0088D9A0, D_006A2D28, &D_0088F0A0);
    }
    return &D_0088D9A0;
}
