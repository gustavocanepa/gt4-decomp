typedef unsigned int u32;

extern "C" void func_005EE7A0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E618[];
extern int D_0088EAC0;

extern int D_0088EE10;

extern "C" void *func_005F1138(void) {
    if (D_0088EE10 == 0) {
        func_005EE7A0();
        func_005BFB68(&D_0088EE10, D_0069E618, &D_0088EAC0);
    }
    return &D_0088EE10;
}
