typedef unsigned int u32;

extern "C" void func_00601238();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A6360[];
extern int D_0088FC90;

extern int D_0088FD40;

extern "C" void *func_00602A20(void) {
    if (D_0088FD40 == 0) {
        func_00601238();
        func_005BFB68(&D_0088FD40, D_006A6360, &D_0088FC90);
    }
    return &D_0088FD40;
}
