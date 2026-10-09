extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A7C68[];

extern int D_006D60F0;

extern "C" void *func_00603BA8(void) {
    if (D_006D60F0 == 0) {
        func_005BFB88(&D_006D60F0, D_006A7C68);
    }
    return &D_006D60F0;
}
