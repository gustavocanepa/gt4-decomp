extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A0178[];

extern int D_006D5FA8;

extern "C" void *CarGeometryBase__tf(void) {
    if (D_006D5FA8 == 0) {
        func_005BFB88(&D_006D5FA8, D_006A0178);
    }
    return &D_006D5FA8;
}
