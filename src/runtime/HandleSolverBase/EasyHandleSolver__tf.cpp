typedef unsigned int u32;

extern "C" void HandleSolverBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6080;

extern int D_0088FAD0;

extern "C" void *EasyHandleSolver__tf(void) {
    if (D_0088FAD0 == 0) {
        HandleSolverBase__tf();
        func_005BFB68(&D_0088FAD0, ((char *)"16EasyHandleSolver"), &D_006D6080);
    }
    return &D_0088FAD0;
}
