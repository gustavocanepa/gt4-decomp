typedef unsigned int u32;

extern "C" void func_005D5828();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069CB88[];
extern int D_0088E060;

extern int D_0088E8E0;

extern "C" void *func_005EA1F0(void) {
    if (D_0088E8E0 == 0) {
        func_005D5828();
        func_005BFB68(&D_0088E8E0, D_0069CB88, &D_0088E060);
    }
    return &D_0088E8E0;
}
