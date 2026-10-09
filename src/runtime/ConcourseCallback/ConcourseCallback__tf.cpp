typedef unsigned int u32;

extern "C" void func_00604AB0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A44C0[];
extern int D_006D6110;

extern int D_0088FA50;

extern "C" void *ConcourseCallback__tf(void) {
    if (D_0088FA50 == 0) {
        func_00604AB0();
        func_005BFB68(&D_0088FA50, D_006A44C0, &D_006D6110);
    }
    return &D_0088FA50;
}
