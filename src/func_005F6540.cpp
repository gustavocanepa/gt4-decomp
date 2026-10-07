typedef unsigned int u32;

extern "C" void func_005F6450();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069FD98[];
extern int D_0088F1D0;

static int D_0088D9A0;

extern "C" void *func_005F6540(void) {
    if (D_0088D9A0 == 0) {
        func_005F6450();
        func_005BFB68(&D_0088D9A0, D_0069FD98, &D_0088F1D0);
    }
    return &D_0088D9A0;
}
