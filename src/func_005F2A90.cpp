extern "C" void func_005FB200();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F090[];
extern int D_006D6008;

extern int D_0088EF40;

extern "C" void *func_005F2A90(void) {
    if (D_0088EF40 == 0) {
        func_005FB200();
        func_005BFB68(&D_0088EF40, D_0069F090, &D_006D6008);
    }
    return &D_0088EF40;
}
