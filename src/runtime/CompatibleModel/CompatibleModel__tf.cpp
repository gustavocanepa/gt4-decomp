typedef unsigned int u32;

extern "C" void MModel__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00698860[];
extern int D_006D5EB8;

extern int D_0088E210;

extern "C" void *CompatibleModel__tf(void) {
    if (D_0088E210 == 0) {
        MModel__tf();
        func_005BFB68(&D_0088E210, D_00698860, &D_006D5EB8);
    }
    return &D_0088E210;
}
