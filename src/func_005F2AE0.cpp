typedef unsigned int u32;

extern "C" void func_005F2A90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F0B0[];
extern int D_0088EF40;

static int D_0088D9A0;

extern "C" void *func_005F2AE0(void) {
    if (D_0088D9A0 == 0) {
        func_005F2A90();
        func_005BFB68(&D_0088D9A0, D_0069F0B0, &D_0088EF40);
    }
    return &D_0088D9A0;
}
