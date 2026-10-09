typedef unsigned int u32;

extern "C" void func_005FF1E0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069FCD8[];
extern int D_0088FA30;

extern int D_0088F1A0;

extern "C" void *func_005F6210(void) {
    if (D_0088F1A0 == 0) {
        func_005FF1E0();
        func_005BFB68(&D_0088F1A0, D_0069FCD8, &D_0088FA30);
    }
    return &D_0088F1A0;
}
