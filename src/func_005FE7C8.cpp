typedef unsigned int u32;

extern "C" void func_005FE6F0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3DF8[];
extern int D_0088F920;

static int D_0088D9A0;

extern "C" void *func_005FE7C8(void) {
    if (D_0088D9A0 == 0) {
        func_005FE6F0();
        func_005BFB68(&D_0088D9A0, D_006A3DF8, &D_0088F920);
    }
    return &D_0088D9A0;
}
