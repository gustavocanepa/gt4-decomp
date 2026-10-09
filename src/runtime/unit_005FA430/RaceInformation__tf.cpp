extern "C" void func_005BFB88(void *a0, void *a1);


extern int D_006D6008;

extern "C" void *RaceInformation__tf(void) {
    if (D_006D6008 == 0) {
        func_005BFB88(&D_006D6008, ((char *)"15RaceInformation"));
    }
    return &D_006D6008;
}
