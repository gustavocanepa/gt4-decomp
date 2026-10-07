typedef unsigned int u32;

extern "C" void func_005F7978();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1298[];
extern int D_0088F340;

extern int D_0088F350;

extern "C" void *func_005F7A30(void) {
    if (D_0088F350 == 0) {
        func_005F7978();
        func_005BFB68(&D_0088F350, D_006A1298, &D_0088F340);
    }
    return &D_0088F350;
}
