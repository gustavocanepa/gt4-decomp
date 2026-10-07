typedef unsigned int u32;

extern "C" void func_005EE7A0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E5C8[];
extern int D_0088EAC0;

extern int D_0088ECA0;

extern "C" void *func_005F0FA8(void) {
    if (D_0088ECA0 == 0) {
        func_005EE7A0();
        func_005BFB68(&D_0088ECA0, D_0069E5C8, &D_0088EAC0);
    }
    return &D_0088ECA0;
}
