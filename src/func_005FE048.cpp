typedef unsigned int u32;

extern "C" void func_005FDFF8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A36B8[];
extern int D_0088F870;

static int D_0088D9A0;

extern "C" void *func_005FE048(void) {
    if (D_0088D9A0 == 0) {
        func_005FDFF8();
        func_005BFB68(&D_0088D9A0, D_006A36B8, &D_0088F870);
    }
    return &D_0088D9A0;
}
