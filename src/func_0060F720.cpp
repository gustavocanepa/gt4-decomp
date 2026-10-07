typedef unsigned int u32;

extern "C" void func_0060F6E0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C0FB8[];
extern int D_006D6208;

extern int D_008A00D0;

extern "C" void *func_0060F720(void) {
    if (D_008A00D0 == 0) {
        func_0060F6E0();
        func_005BFB68(&D_008A00D0, D_006C0FB8, &D_006D6208);
    }
    return &D_008A00D0;
}
