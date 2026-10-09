typedef unsigned int u32;

extern "C" void func_00613DD8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B0148[];
extern int D_006D62D8;

extern int D_0088FF28;

extern "C" void *func_0060ABF8(void) {
    if (D_0088FF28 == 0) {
        func_00613DD8();
        func_005BFB68(&D_0088FF28, D_006B0148, &D_006D62D8);
    }
    return &D_0088FF28;
}
