extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A4268[];

extern int D_006D6068;

extern "C" void *func_005FF0B8(void) {
    if (D_006D6068 == 0) {
        func_005BFB88(&D_006D6068, D_006A4268);
    }
    return &D_006D6068;
}
