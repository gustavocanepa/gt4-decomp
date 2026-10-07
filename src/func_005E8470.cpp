typedef unsigned int u32;

extern "C" void func_005CA408();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069C050[];
extern int D_006D5E20;

extern int D_0088E7A0;

extern "C" void *func_005E8470(void) {
    if (D_0088E7A0 == 0) {
        func_005CA408();
        func_005BFB68(&D_0088E7A0, D_0069C050, &D_006D5E20);
    }
    return &D_0088E7A0;
}
