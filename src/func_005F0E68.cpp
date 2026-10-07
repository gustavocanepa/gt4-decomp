typedef unsigned int u32;

extern "C" void func_005EE7A0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E578[];
extern int D_0088EAC0;

extern int D_0088EE70;

extern "C" void *func_005F0E68(void) {
    if (D_0088EE70 == 0) {
        func_005EE7A0();
        func_005BFB68(&D_0088EE70, D_0069E578, &D_0088EAC0);
    }
    return &D_0088EE70;
}
