typedef unsigned int u32;

extern "C" void func_00613DD8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C0ED8[];
extern int D_006D62D8;

extern int D_008A00C0;

extern "C" void *func_0060F600(void) {
    if (D_008A00C0 == 0) {
        func_00613DD8();
        func_005BFB68(&D_008A00C0, D_006C0ED8, &D_006D62D8);
    }
    return &D_008A00C0;
}
