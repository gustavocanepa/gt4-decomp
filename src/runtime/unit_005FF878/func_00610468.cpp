typedef unsigned int u32;

extern "C" void func_00612FF0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D62B8;

extern int D_008A15D0;

extern "C" void *func_00610468(void) {
    if (D_008A15D0 == 0) {
        func_00612FF0();
        func_005BFB68(&D_008A15D0, ((char *)"Q237_GLOBAL_$N$ps2_misc_pdipipe.cxxpg5mtZ3RPC"), &D_006D62B8);
    }
    return &D_008A15D0;
}
