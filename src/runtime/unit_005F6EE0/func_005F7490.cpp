typedef unsigned int u32;

extern "C" void _UnitArenaBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A0378[];
extern int D_006D6120;

extern int D_0088F2F0;

extern "C" void *func_005F7490(void) {
    if (D_0088F2F0 == 0) {
        _UnitArenaBase__tf();
        func_005BFB68(&D_0088F2F0, D_006A0378, &D_006D6120);
    }
    return &D_0088F2F0;
}
