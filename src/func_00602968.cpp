typedef unsigned int u32;

extern "C" void func_00601238();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A6338[];
extern int D_0088FC90;

extern int D_0088FD50;

extern "C" void *func_00602968(void) {
    if (D_0088FD50 == 0) {
        func_00601238();
        func_005BFB68(&D_0088FD50, D_006A6338, &D_0088FC90);
    }
    return &D_0088FD50;
}
