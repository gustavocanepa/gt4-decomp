typedef unsigned int u32;

extern "C" void RefPointer__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068FD48[];
extern int D_006D5E20;

extern int D_0088DB50;

extern "C" void *MData__tf(void) {
    if (D_0088DB50 == 0) {
        RefPointer__tf();
        func_005BFB68(&D_0088DB50, D_0068FD48, &D_006D5E20);
    }
    return &D_0088DB50;
}
