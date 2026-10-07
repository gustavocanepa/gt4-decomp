typedef unsigned int u32;

extern "C" void func_00611898();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C8A90[];
extern int D_006D6260;

extern int D_008A1A90;

extern "C" void *func_006118F8(void) {
    if (D_008A1A90 == 0) {
        func_00611898();
        func_005BFB68(&D_008A1A90, D_006C8A90, &D_006D6260);
    }
    return &D_008A1A90;
}
