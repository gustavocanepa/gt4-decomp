typedef unsigned int u32;

extern "C" void func_00612D10();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_008A1B40;

extern int D_0088FF38;

extern "C" void *func_0060AC48(void) {
    if (D_0088FF38 == 0) {
        func_00612D10();
        func_005BFB68(&D_0088FF38, ((char *)"Q26PDISTD10FileExpand"), &D_008A1B40);
    }
    return &D_0088FF38;
}
