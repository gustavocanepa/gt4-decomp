extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A00C8[];

extern int D_006D5F98;

extern "C" void *RaceDisplayBase__tf(void) {
    if (D_006D5F98 == 0) {
        func_005BFB88(&D_006D5F98, D_006A00C8);
    }
    return &D_006D5F98;
}
