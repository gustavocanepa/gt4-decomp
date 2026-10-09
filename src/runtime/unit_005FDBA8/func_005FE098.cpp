typedef unsigned int u32;

extern "C" void func_005FDFF8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A36D0[];
extern int D_0088F870;

extern int D_0088F890;

extern "C" void *func_005FE098(void) {
    if (D_0088F890 == 0) {
        func_005FDFF8();
        func_005BFB68(&D_0088F890, D_006A36D0, &D_0088F870);
    }
    return &D_0088F890;
}
