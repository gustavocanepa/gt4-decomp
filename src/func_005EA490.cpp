typedef unsigned int u32;

extern "C" void func_005E59F8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069CFC8[];
extern int D_0088E610;

extern int D_0088E950;

extern "C" void *func_005EA490(void) {
    if (D_0088E950 == 0) {
        func_005E59F8();
        func_005BFB68(&D_0088E950, D_0069CFC8, &D_0088E610);
    }
    return &D_0088E950;
}
