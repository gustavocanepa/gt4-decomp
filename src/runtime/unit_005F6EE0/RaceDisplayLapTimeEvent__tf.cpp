typedef unsigned int u32;

extern "C" void RaceDisplayEventBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A12E0[];
extern int D_006D5FC0;

extern int D_0088F360;

extern "C" void *RaceDisplayLapTimeEvent__tf(void) {
    if (D_0088F360 == 0) {
        RaceDisplayEventBase__tf();
        func_005BFB68(&D_0088F360, D_006A12E0, &D_006D5FC0);
    }
    return &D_0088F360;
}
