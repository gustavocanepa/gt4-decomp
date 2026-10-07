typedef unsigned int u32;

extern "C" void func_005F0DF0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E598[];
extern int D_0088EDF0;

extern int D_0088EE50;

extern "C" void *func_005F0F08(void) {
    if (D_0088EE50 == 0) {
        func_005F0DF0();
        func_005BFB68(&D_0088EE50, D_0069E598, &D_0088EDF0);
    }
    return &D_0088EE50;
}
