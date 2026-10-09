typedef unsigned int u32;

extern "C" void filebuf__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006CFFE8[];
extern int D_008A1C20;

extern int D_008A1C70;

extern "C" void *stdiobuf__tf(void) {
    if (D_008A1C70 == 0) {
        filebuf__tf();
        func_005BFB68(&D_008A1C70, D_006CFFE8, &D_008A1C20);
    }
    return &D_008A1C70;
}
