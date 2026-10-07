typedef unsigned int u32;

extern "C" void func_005DCDB8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A7F8[];
extern int D_0088E2F0;

extern int D_0088E4D0;

extern "C" void *func_005E40D0(void) {
    if (D_0088E4D0 == 0) {
        func_005DCDB8();
        func_005BFB68(&D_0088E4D0, D_0069A7F8, &D_0088E2F0);
    }
    return &D_0088E4D0;
}
