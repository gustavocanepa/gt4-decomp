typedef unsigned int u32;

extern "C" void func_005FE0E8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3938[];
extern int D_0088F8B0;

extern int D_0088F8C0;

extern "C" void *func_005FE258(void) {
    if (D_0088F8C0 == 0) {
        func_005FE0E8();
        func_005BFB68(&D_0088F8C0, D_006A3938, &D_0088F8B0);
    }
    return &D_0088F8C0;
}
