typedef unsigned int u32;

extern "C" void func_005F6A70();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1258[];
extern int D_006D5F98;

extern int D_0088F330;

extern "C" void *func_005F76F8(void) {
    if (D_0088F330 == 0) {
        func_005F6A70();
        func_005BFB68(&D_0088F330, D_006A1258, &D_006D5F98);
    }
    return &D_0088F330;
}
