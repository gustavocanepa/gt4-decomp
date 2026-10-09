extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A6090[];

extern int D_006D60A8;

extern "C" void *func_00602300(void) {
    if (D_006D60A8 == 0) {
        func_005BFB88(&D_006D60A8, D_006A6090);
    }
    return &D_006D60A8;
}
