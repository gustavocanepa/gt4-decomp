typedef unsigned int u32;

extern "C" void func_005EE750();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069EFB8[];
extern int D_0088EAB0;

extern int D_0088EEE0;

extern "C" void *func_005F2808(void) {
    if (D_0088EEE0 == 0) {
        func_005EE750();
        func_005BFB68(&D_0088EEE0, D_0069EFB8, &D_0088EAB0);
    }
    return &D_0088EEE0;
}
