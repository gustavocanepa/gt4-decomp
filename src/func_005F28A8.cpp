typedef unsigned int u32;

extern "C" void func_005F1C00();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F068[];
extern int D_0088EE90;

extern int D_0088EF00;

extern "C" void *func_005F28A8(void) {
    if (D_0088EF00 == 0) {
        func_005F1C00();
        func_005BFB68(&D_0088EF00, D_0069F068, &D_0088EE90);
    }
    return &D_0088EF00;
}
