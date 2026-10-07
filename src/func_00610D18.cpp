typedef unsigned int u32;

extern "C" void func_00612FF0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C86F8[];
extern int D_006D62B8;

static int D_0088D9A0;

extern "C" void *func_00610D18(void) {
    if (D_0088D9A0 == 0) {
        func_00612FF0();
        func_005BFB68(&D_0088D9A0, D_006C86F8, &D_006D62B8);
    }
    return &D_0088D9A0;
}
