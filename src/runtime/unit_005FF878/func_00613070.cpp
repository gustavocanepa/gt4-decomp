typedef unsigned int u32;

extern "C" void func_00613C38();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006CC6B8[];
extern int D_006D62D0;

extern int D_008A1B80;

extern "C" void *func_00613070(void) {
    if (D_008A1B80 == 0) {
        func_00613C38();
        func_005BFB68(&D_008A1B80, D_006CC6B8, &D_006D62D0);
    }
    return &D_008A1B80;
}
