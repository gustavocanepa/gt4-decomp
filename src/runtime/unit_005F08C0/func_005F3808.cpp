typedef unsigned int u32;

extern "C" void ComputeDriverPostureCaller__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5F68;

extern int D_0088F010;

extern "C" void *func_005F3808(void) {
    if (D_0088F010 == 0) {
        ComputeDriverPostureCaller__tf();
        func_005BFB68(&D_0088F010, ((char *)"Q28GT4Model21RecordedDriverPosture"), &D_006D5F68);
    }
    return &D_0088F010;
}
