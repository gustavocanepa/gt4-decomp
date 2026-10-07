typedef unsigned int u32;

extern "C" void func_005D5828();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A8C0[];
extern int D_0088E060;

extern int D_0088E4F0;

extern "C" void *func_005E4208(void) {
    if (D_0088E4F0 == 0) {
        func_005D5828();
        func_005BFB68(&D_0088E4F0, D_0069A8C0, &D_0088E060);
    }
    return &D_0088E4F0;
}
