typedef unsigned int u32;

extern "C" void func_005D5828();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069CB78[];
extern int D_0088E060;

extern int D_0088E900;

extern "C" void *func_005EA188(void) {
    if (D_0088E900 == 0) {
        func_005D5828();
        func_005BFB68(&D_0088E900, D_0069CB78, &D_0088E060);
    }
    return &D_0088E900;
}
