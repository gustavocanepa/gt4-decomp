typedef unsigned int u32;

extern "C" void func_005C21E0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068BFF8[];
extern int D_0088D9E0;

extern int D_0088D9C0;

extern "C" void *func_005C2328(void) {
    if (D_0088D9C0 == 0) {
        func_005C21E0();
        func_005BFB68(&D_0088D9C0, D_0068BFF8, &D_0088D9E0);
    }
    return &D_0088D9C0;
}
