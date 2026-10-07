typedef unsigned int u32;

extern "C" void func_00612FA0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006CC5C8[];
extern int D_008A1B70;

static int D_0088D9A0;

extern "C" void *func_00612F50(void) {
    if (D_0088D9A0 == 0) {
        func_00612FA0();
        func_005BFB68(&D_0088D9A0, D_006CC5C8, &D_008A1B70);
    }
    return &D_0088D9A0;
}
