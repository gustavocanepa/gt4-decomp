typedef unsigned int u32;

extern "C" void func_00603E48();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F998[];
extern int D_0088FE20;

extern int D_0088F090;

extern "C" void *func_005F52A0(void) {
    if (D_0088F090 == 0) {
        func_00603E48();
        func_005BFB68(&D_0088F090, D_0069F998, &D_0088FE20);
    }
    return &D_0088F090;
}
