typedef unsigned int u32;

extern "C" void func_005E5988();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069B180[];
extern int D_0088E600;

extern int D_0088E620;

extern "C" void *func_005E5A48(void) {
    if (D_0088E620 == 0) {
        func_005E5988();
        func_005BFB68(&D_0088E620, D_0069B180, &D_0088E600);
    }
    return &D_0088E620;
}
