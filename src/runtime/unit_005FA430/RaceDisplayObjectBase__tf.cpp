extern "C" void func_005BFB88(void *a0, void *a1);


extern int D_006D5FC8;

extern "C" void *RaceDisplayObjectBase__tf(void) {
    if (D_006D5FC8 == 0) {
        func_005BFB88(&D_006D5FC8, ((char *)"21RaceDisplayObjectBase"));
    }
    return &D_006D5FC8;
}
