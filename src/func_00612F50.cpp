typedef unsigned int u32;

extern "C" void func_00612FA0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006CC5C8[];
extern int D_008A1B70;

extern int D_008A1B60;

extern "C" void *func_00612F50(void) {
    if (D_008A1B60 == 0) {
        func_00612FA0();
        func_005BFB68(&D_008A1B60, D_006CC5C8, &D_008A1B70);
    }
    return &D_008A1B60;
}
