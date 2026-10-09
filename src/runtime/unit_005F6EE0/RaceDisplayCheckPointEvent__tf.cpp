typedef unsigned int u32;

extern "C" void RaceDisplayLapTimeEvent__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F360;

extern int D_0088F3D0;

extern "C" void *RaceDisplayCheckPointEvent__tf(void) {
    if (D_0088F3D0 == 0) {
        RaceDisplayLapTimeEvent__tf();
        func_005BFB68(&D_0088F3D0, ((char *)"26RaceDisplayCheckPointEvent"), &D_0088F360);
    }
    return &D_0088F3D0;
}
