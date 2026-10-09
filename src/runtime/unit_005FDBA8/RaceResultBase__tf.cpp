extern "C" void func_005BFB88(void *a0, void *a1);


extern int D_006D6048;

extern "C" void *RaceResultBase__tf(void) {
    if (D_006D6048 == 0) {
        func_005BFB88(&D_006D6048, ((char *)"14RaceResultBase"));
    }
    return &D_006D6048;
}
