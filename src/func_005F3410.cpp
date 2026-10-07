typedef unsigned int u32;

extern "C" void func_005F6AB0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F1D0[];
extern int D_0088F230;

extern int D_0088EF90;

extern "C" void *func_005F3410(void) {
    if (D_0088EF90 == 0) {
        func_005F6AB0();
        func_005BFB68(&D_0088EF90, D_0069F1D0, &D_0088F230);
    }
    return &D_0088EF90;
}
