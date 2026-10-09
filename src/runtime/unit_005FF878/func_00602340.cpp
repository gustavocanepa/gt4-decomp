extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A60B8[];

extern int D_006D60A0;

extern "C" void *func_00602340(void) {
    if (D_006D60A0 == 0) {
        func_005BFB88(&D_006D60A0, D_006A60B8);
    }
    return &D_006D60A0;
}
