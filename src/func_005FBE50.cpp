typedef unsigned int u32;

extern "C" void func_005FBF70();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A2B38[];
extern int D_006D6030;

extern int D_0088F790;

extern "C" void *func_005FBE50(void) {
    if (D_0088F790 == 0) {
        func_005FBF70();
        func_005BFB68(&D_0088F790, D_006A2B38, &D_006D6030);
    }
    return &D_0088F790;
}
