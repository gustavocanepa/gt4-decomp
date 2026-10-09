extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006B0130[];

extern int D_006D61A0;

extern "C" void *func_0060A750(void) {
    if (D_006D61A0 == 0) {
        func_005BFB88(&D_006D61A0, D_006B0130);
    }
    return &D_006D61A0;
}
