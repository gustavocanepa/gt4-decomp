typedef unsigned int u32;

extern "C" void func_005F2B30();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F0E8[];
extern int D_0088EF20;

extern int D_0088EF30;

extern "C" void *func_005F2B80(void) {
    if (D_0088EF30 == 0) {
        func_005F2B30();
        func_005BFB68(&D_0088EF30, D_0069F0E8, &D_0088EF20);
    }
    return &D_0088EF30;
}
