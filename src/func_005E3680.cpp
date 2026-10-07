typedef unsigned int u32;

extern "C" void func_005DC658();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A5C8[];
extern int D_0088E2A0;

extern int D_0088E490;

extern "C" void *func_005E3680(void) {
    if (D_0088E490 == 0) {
        func_005DC658();
        func_005BFB68(&D_0088E490, D_0069A5C8, &D_0088E2A0);
    }
    return &D_0088E490;
}
