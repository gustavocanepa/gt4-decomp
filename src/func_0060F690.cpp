typedef unsigned int u32;

extern "C" void func_0060F650();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C0F40[];
extern int D_006D6220;

extern int D_008A00F0;

extern "C" void *func_0060F690(void) {
    if (D_008A00F0 == 0) {
        func_0060F650();
        func_005BFB68(&D_008A00F0, D_006C0F40, &D_006D6220);
    }
    return &D_008A00F0;
}
