typedef unsigned int u32;

extern "C" void streambuf__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006CF890[];
extern int D_008A1C30;

extern int D_008A1C20;

extern "C" void *filebuf__tf(void) {
    if (D_008A1C20 == 0) {
        streambuf__tf();
        func_005BFB68(&D_008A1C20, D_006CF890, &D_008A1C30);
    }
    return &D_008A1C20;
}
