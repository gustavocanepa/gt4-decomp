typedef unsigned int u32;

extern "C" void func_005F6AB0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3C10[];
extern int D_0088F230;

extern int D_0088F8F0;

extern "C" void *func_005FE4F0(void) {
    if (D_0088F8F0 == 0) {
        func_005F6AB0();
        func_005BFB68(&D_0088F8F0, D_006A3C10, &D_0088F230);
    }
    return &D_0088F8F0;
}
