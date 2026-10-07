typedef unsigned int u32;

extern "C" void func_005D5828();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697210[];
extern int D_0088E060;

extern int D_0088E020;

extern "C" void *func_005D50C8(void) {
    if (D_0088E020 == 0) {
        func_005D5828();
        func_005BFB68(&D_0088E020, D_00697210, &D_0088E060);
    }
    return &D_0088E020;
}
