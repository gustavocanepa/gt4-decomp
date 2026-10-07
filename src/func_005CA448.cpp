typedef unsigned int u32;

extern "C" void func_005CA210();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068FE10[];
extern int D_0088DB40;

extern int D_0088DB70;

extern "C" void *func_005CA448(void) {
    if (D_0088DB70 == 0) {
        func_005CA210();
        func_005BFB68(&D_0088DB70, D_0068FE10, &D_0088DB40);
    }
    return &D_0088DB70;
}
