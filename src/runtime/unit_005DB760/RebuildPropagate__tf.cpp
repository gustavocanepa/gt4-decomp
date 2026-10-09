typedef unsigned int u32;

extern "C" void MAction__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00698A90[];
extern int D_006D5EE8;

extern int D_0088E250;

extern "C" void *RebuildPropagate__tf(void) {
    if (D_0088E250 == 0) {
        MAction__tf();
        func_005BFB68(&D_0088E250, D_00698A90, &D_006D5EE8);
    }
    return &D_0088E250;
}
