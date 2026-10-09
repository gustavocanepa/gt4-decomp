typedef unsigned int u32;

extern "C" void func_005C1F98();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088D960;

extern int D_0088F210;

extern "C" void *RaceBase__tf(void) {
    if (D_0088F210 == 0) {
        func_005C1F98();
        func_005BFB68(&D_0088F210, ((char *)"8RaceBase"), &D_0088D960);
    }
    return &D_0088F210;
}
