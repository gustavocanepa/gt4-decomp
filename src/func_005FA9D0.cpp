typedef unsigned int u32;

extern "C" void func_005FA8E0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A23D8[];
extern int D_006D5FD0;

extern int D_0088F690;

extern "C" void *func_005FA9D0(void) {
    if (D_0088F690 == 0) {
        func_005FA8E0();
        func_005BFB68(&D_0088F690, D_006A23D8, &D_006D5FD0);
    }
    return &D_0088F690;
}
