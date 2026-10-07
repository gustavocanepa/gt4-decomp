typedef int s32;

extern "C" void func_00614570();
extern "C" void func_005BFB40(void *a0, void *a1, void *a2, s32 a3);

extern char D_006CFFF8[];
extern int D_006D0008;

extern int D_008A1C60;

extern "C" void *func_00615D80(void) {
    if (D_008A1C60 == 0) {
        func_00614570();
        func_005BFB40(&D_008A1C60, D_006CFFF8, &D_006D0008, 1);
    }
    return &D_008A1C60;
}
