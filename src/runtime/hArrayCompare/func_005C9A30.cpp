typedef unsigned int u32;

extern "C" void hArrayCompare__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068F560[];
extern int D_006D5E30;

extern int D_0088DB20;

extern "C" void *func_005C9A30(void) {
    if (D_0088DB20 == 0) {
        hArrayCompare__tf();
        func_005BFB68(&D_0088DB20, D_0068F560, &D_006D5E30);
    }
    return &D_0088DB20;
}
