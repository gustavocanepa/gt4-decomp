typedef unsigned int u32;

extern "C" void exception__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006D3020[];
extern int D_006D6308;

extern int D_008A2080;

extern "C" void *bad_typeid__tf(void) {
    if (D_008A2080 == 0) {
        exception__tf();
        func_005BFB68(&D_008A2080, D_006D3020, &D_006D6308);
    }
    return &D_008A2080;
}
