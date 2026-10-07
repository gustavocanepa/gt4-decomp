typedef unsigned int u32;

extern "C" void func_00613DD8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C8648[];
extern int D_006D62D8;

extern int D_008A15F0;

extern "C" void *func_00610B98(void) {
    if (D_008A15F0 == 0) {
        func_00613DD8();
        func_005BFB68(&D_008A15F0, D_006C8648, &D_006D62D8);
    }
    return &D_008A15F0;
}
