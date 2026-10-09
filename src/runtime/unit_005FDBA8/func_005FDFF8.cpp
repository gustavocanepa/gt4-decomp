typedef unsigned int u32;

extern "C" void func_00603BE8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A36A0[];
extern int D_006D60F8;

extern int D_0088F870;

extern "C" void *func_005FDFF8(void) {
    if (D_0088F870 == 0) {
        func_00603BE8();
        func_005BFB68(&D_0088F870, D_006A36A0, &D_006D60F8);
    }
    return &D_0088F870;
}
