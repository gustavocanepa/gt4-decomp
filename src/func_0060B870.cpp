extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006B03C8[];

extern int D_006D61C0;

extern "C" void *func_0060B870(void) {
    if (D_006D61C0 == 0) {
        func_005BFB88(&D_006D61C0, D_006B03C8);
    }
    return &D_006D61C0;
}
