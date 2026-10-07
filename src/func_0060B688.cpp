typedef unsigned int u32;

extern "C" void func_00612E68();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B0300[];
extern int D_006D62A8;

extern int D_0089FFF0;

extern "C" void *func_0060B688(void) {
    if (D_0089FFF0 == 0) {
        func_00612E68();
        func_005BFB68(&D_0089FFF0, D_006B0300, &D_006D62A8);
    }
    return &D_0089FFF0;
}
