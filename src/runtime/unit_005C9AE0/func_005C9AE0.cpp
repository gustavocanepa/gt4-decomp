typedef unsigned int u32;

extern "C" void hArrayCompare__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5E30;

extern int D_0088DB10;

extern "C" void *func_005C9AE0(void) {
    if (D_0088DB10 == 0) {
        hArrayCompare__tf();
        func_005BFB68(&D_0088DB10, ((char *)"Q240_GLOBAL_$N$__10MCarGarageRC11RefCounterP10CompareRev"), &D_006D5E30);
    }
    return &D_0088DB10;
}
