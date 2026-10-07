typedef unsigned int u32;

extern "C" void func_005CF618();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00693B58[];
extern int D_0088DDA0;

extern int D_0088DDF0;

extern "C" void *func_005D08A0(void) {
    if (D_0088DDF0 == 0) {
        func_005CF618();
        func_005BFB68(&D_0088DDF0, D_00693B58, &D_0088DDA0);
    }
    return &D_0088DDF0;
}
