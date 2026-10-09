typedef unsigned int u32;

extern "C" void func_00612FF0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D62B8;

extern int D_008A1590;

extern "C" void *func_0060FAA0(void) {
    if (D_008A1590 == 0) {
        func_00612FF0();
        func_005BFB68(&D_008A1590, ((char *)"Q232_GLOBAL_$N$ps2_bgm_bgm.cxxopMmw83RPC"), &D_006D62B8);
    }
    return &D_008A1590;
}
