typedef unsigned int u32;

extern "C" void func_005CA878();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5E58;

extern int D_0088DFB0;

extern "C" void *func_005D2AA8(void) {
    if (D_0088DFB0 == 0) {
        func_005CA878();
        func_005BFB68(&D_0088DFB0, ((char *)"Q312GT4CarSelect45_GLOBAL_$N$__Q212GT4CarSelect14AnimationStage19CustumLightPosition"), &D_006D5E58);
    }
    return &D_0088DFB0;
}
