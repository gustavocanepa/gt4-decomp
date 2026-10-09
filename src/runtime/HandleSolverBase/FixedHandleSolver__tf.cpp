typedef unsigned int u32;

extern "C" void HandleSolverBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A47C8[];
extern int D_006D6080;

extern int D_0088FAB0;

extern "C" void *FixedHandleSolver__tf(void) {
    if (D_0088FAB0 == 0) {
        HandleSolverBase__tf();
        func_005BFB68(&D_0088FAB0, D_006A47C8, &D_006D6080);
    }
    return &D_0088FAB0;
}
