typedef unsigned int u32;

extern "C" void func_005CA878();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5E58;

extern int D_0088DB60;

extern "C" void *func_005CA5A0(void) {
    if (D_0088DB60 == 0) {
        func_005CA878();
        func_005BFB68(&D_0088DB60, ((char *)"Q236_GLOBAL_$N$rc_class__C12mCarModelPS219CustumLightPosition"), &D_006D5E58);
    }
    return &D_0088DB60;
}
