typedef unsigned int u32;

extern "C" void func_00612498();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C8628[];
extern int D_006D6270;

extern int D_008A1600;

extern "C" void *func_00610AE0(void) {
    if (D_008A1600 == 0) {
        func_00612498();
        func_005BFB68(&D_008A1600, D_006C8628, &D_006D6270);
    }
    return &D_008A1600;
}
