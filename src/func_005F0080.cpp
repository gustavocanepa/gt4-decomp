typedef unsigned int u32;

extern "C" void func_005F1C00();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E128[];
extern int D_0088EE90;

extern int D_0088EBA0;

extern "C" void *func_005F0080(void) {
    if (D_0088EBA0 == 0) {
        func_005F1C00();
        func_005BFB68(&D_0088EBA0, D_0069E128, &D_0088EE90);
    }
    return &D_0088EBA0;
}
