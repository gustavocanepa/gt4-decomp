typedef unsigned int u32;

extern "C" void func_005FDD30();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3E68[];
extern int D_0088F830;

extern int D_0088F950;

extern "C" void *func_005FE908(void) {
    if (D_0088F950 == 0) {
        func_005FDD30();
        func_005BFB68(&D_0088F950, D_006A3E68, &D_0088F830);
    }
    return &D_0088F950;
}
