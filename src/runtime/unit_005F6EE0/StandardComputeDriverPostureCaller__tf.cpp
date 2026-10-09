typedef unsigned int u32;

extern "C" void ComputeDriverPostureCaller__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A0208[];
extern int D_006D5F68;

extern int D_0088F290;

extern "C" void *StandardComputeDriverPostureCaller__tf(void) {
    if (D_0088F290 == 0) {
        ComputeDriverPostureCaller__tf();
        func_005BFB68(&D_0088F290, D_006A0208, &D_006D5F68);
    }
    return &D_0088F290;
}
