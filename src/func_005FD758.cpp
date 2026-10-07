typedef unsigned int u32;

extern "C" void func_005F3AE0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A2D48[];
extern int D_0088F020;

static int D_0088D9A0;

extern "C" void *func_005FD758(void) {
    if (D_0088D9A0 == 0) {
        func_005F3AE0();
        func_005BFB68(&D_0088D9A0, D_006A2D48, &D_0088F020);
    }
    return &D_0088D9A0;
}
