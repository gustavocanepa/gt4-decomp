typedef unsigned int u32;

extern "C" void func_005F32B8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F238[];
extern int D_0088EF70;

extern int D_0088EFC0;

extern "C" void *func_005F34F8(void) {
    if (D_0088EFC0 == 0) {
        func_005F32B8();
        func_005BFB68(&D_0088EFC0, D_0069F238, &D_0088EF70);
    }
    return &D_0088EFC0;
}
