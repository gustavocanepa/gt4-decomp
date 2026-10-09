extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_00698A68[];

extern int D_006D5ED8;

extern "C" void *MRegion__tf(void) {
    if (D_006D5ED8 == 0) {
        func_005BFB88(&D_006D5ED8, D_00698A68);
    }
    return &D_006D5ED8;
}
