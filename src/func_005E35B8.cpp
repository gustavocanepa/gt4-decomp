typedef unsigned int u32;

extern "C" void func_005DA840();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A588[];
extern int D_0088E190;

extern int D_0088E480;

extern "C" void *func_005E35B8(void) {
    if (D_0088E480 == 0) {
        func_005DA840();
        func_005BFB68(&D_0088E480, D_0069A588, &D_0088E190);
    }
    return &D_0088E480;
}
