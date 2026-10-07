typedef unsigned int u32;

extern "C" void func_005D4F58();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069D168[];
extern int D_0088E000;

static int D_0088D9A0;

extern "C" void *func_005EA808(void) {
    if (D_0088D9A0 == 0) {
        func_005D4F58();
        func_005BFB68(&D_0088D9A0, D_0069D168, &D_0088E000);
    }
    return &D_0088D9A0;
}
