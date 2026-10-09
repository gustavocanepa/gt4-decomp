extern "C" void func_005BFB88(void *a0, void *a1);


extern int D_006D5FC0;

extern "C" void *RaceDisplayEventBase__tf(void) {
    if (D_006D5FC0 == 0) {
        func_005BFB88(&D_006D5FC0, ((char *)"20RaceDisplayEventBase"));
    }
    return &D_006D5FC0;
}
