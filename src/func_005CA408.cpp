typedef unsigned int u32;

extern "C" void func_005BFB88(void *a0, char *a1);
extern "C" void func_005CA210();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068FD50[];
extern char D_0068FE10[];

static int D_006D5E20;
static int D_0088DB70;

extern "C" void *func_005CA408(void) {
    if (D_006D5E20 == 0) {
        func_005BFB88(&D_006D5E20, D_0068FD50);
    }
    return &D_006D5E20;
}

extern "C" void *func_005CA448(void) {
    if (D_0088DB70 == 0) {
        func_005CA210();
        func_005BFB68(&D_0088DB70, D_0068FE10, &D_006D5E20);
    }
    return &D_0088DB70;
}
