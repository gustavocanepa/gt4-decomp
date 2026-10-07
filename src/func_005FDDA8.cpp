typedef unsigned int u32;

extern "C" void func_005F6C00();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3290[];
extern int D_0088F220;

extern int D_0088F840;

extern "C" void *func_005FDDA8(void) {
    if (D_0088F840 == 0) {
        func_005F6C00();
        func_005BFB68(&D_0088F840, D_006A3290, &D_0088F220);
    }
    return &D_0088F840;
}
