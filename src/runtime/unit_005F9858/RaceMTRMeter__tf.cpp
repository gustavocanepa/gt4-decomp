typedef unsigned int u32;

extern "C" void RaceDisplayObjectBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5FC8;

extern int D_0088F580;

extern "C" void *RaceMTRMeter__tf(void) {
    if (D_0088F580 == 0) {
        RaceDisplayObjectBase__tf();
        func_005BFB68(&D_0088F580, ((char *)"12RaceMTRMeter"), &D_006D5FC8);
    }
    return &D_0088F580;
}
