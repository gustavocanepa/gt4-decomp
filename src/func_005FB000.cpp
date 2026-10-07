extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A2628[];

extern int D_006D5FF0;

extern "C" void *func_005FB000(void) {
    if (D_006D5FF0 == 0) {
        func_005BFB88(&D_006D5FF0, D_006A2628);
    }
    return &D_006D5FF0;
}
