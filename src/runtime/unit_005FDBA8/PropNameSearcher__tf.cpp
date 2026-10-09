typedef unsigned int u32;

extern "C" void func_005FDC20();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6038;

extern int D_0088F810;

extern "C" void *PropNameSearcher__tf(void) {
    if (D_0088F810 == 0) {
        func_005FDC20();
        func_005BFB68(&D_0088F810, ((char *)"16PropNameSearcher"), &D_006D6038);
    }
    return &D_0088F810;
}
