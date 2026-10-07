typedef unsigned int u32;

extern "C" void func_005CA408();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068FD48[];
extern int D_006D5E20;

extern int D_0088DB50;

extern "C" void *func_005CA3B8(void) {
    if (D_0088DB50 == 0) {
        func_005CA408();
        func_005BFB68(&D_0088DB50, D_0068FD48, &D_006D5E20);
    }
    return &D_0088DB50;
}
