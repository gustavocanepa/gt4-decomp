typedef unsigned int u32;

extern "C" void func_005CA210();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068FE10[];
extern int D_0088DB40;

static int D_0088D9A0;

extern "C" void *func_005CA448(void) {
    if (D_0088D9A0 == 0) {
        func_005CA210();
        func_005BFB68(&D_0088D9A0, D_0068FE10, &D_0088DB40);
    }
    return &D_0088D9A0;
}
