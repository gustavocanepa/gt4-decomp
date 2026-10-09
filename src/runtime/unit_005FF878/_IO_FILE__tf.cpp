extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006CF8B0[];

extern int D_006D62F0;

extern "C" void *_IO_FILE__tf(void) {
    if (D_006D62F0 == 0) {
        func_005BFB88(&D_006D62F0, D_006CF8B0);
    }
    return &D_006D62F0;
}
