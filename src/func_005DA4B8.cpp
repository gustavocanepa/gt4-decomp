typedef unsigned int u32;

extern "C" void func_005F26E0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697EC0[];
extern int D_006D5F58;

extern int D_0088E170;

extern "C" void *func_005DA4B8(void) {
    if (D_0088E170 == 0) {
        func_005F26E0();
        func_005BFB68(&D_0088E170, D_00697EC0, &D_006D5F58);
    }
    return &D_0088E170;
}
