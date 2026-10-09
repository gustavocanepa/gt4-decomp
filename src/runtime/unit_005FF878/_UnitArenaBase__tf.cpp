extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006AB928[];

extern int D_006D6120;

extern "C" void *_UnitArenaBase__tf(void) {
    if (D_006D6120 == 0) {
        func_005BFB88(&D_006D6120, D_006AB928);
    }
    return &D_006D6120;
}
