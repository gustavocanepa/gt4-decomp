typedef unsigned int u32;

extern "C" void func_005F2B80();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F100[];
extern int D_0088EF30;

static int D_0088D9A0;

extern "C" void *func_005F2BD8(void) {
    if (D_0088D9A0 == 0) {
        func_005F2B80();
        func_005BFB68(&D_0088D9A0, D_0069F100, &D_0088EF30);
    }
    return &D_0088D9A0;
}
