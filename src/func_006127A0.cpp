typedef unsigned int u32;

extern "C" void func_00612498();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C8DE0[];
extern int D_006D6270;

extern int D_008A1AE0;

extern "C" void *func_006127A0(void) {
    if (D_008A1AE0 == 0) {
        func_00612498();
        func_005BFB68(&D_008A1AE0, D_006C8DE0, &D_006D6270);
    }
    return &D_008A1AE0;
}
