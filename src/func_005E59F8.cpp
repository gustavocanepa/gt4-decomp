extern "C" void func_005D50C8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069B120[];
extern int D_0088E020;

extern int D_0088E610;

extern "C" void *func_005E59F8(void) {
    if (D_0088E610 == 0) {
        func_005D50C8();
        func_005BFB68(&D_0088E610, D_0069B120, &D_0088E020);
    }
    return &D_0088E610;
}
