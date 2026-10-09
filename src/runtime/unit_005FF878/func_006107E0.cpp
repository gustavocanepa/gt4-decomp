typedef unsigned int u32;

extern "C" void func_00612FF0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D62B8;

extern int D_008A15E0;

extern "C" void *func_006107E0(void) {
    if (D_008A15E0 == 0) {
        func_00612FF0();
        func_005BFB68(&D_008A15E0, ((char *)"Q238_GLOBAL_$N$ps2_misc_pdivoice.cxxs2uXJb3RPC"), &D_006D62B8);
    }
    return &D_008A15E0;
}
