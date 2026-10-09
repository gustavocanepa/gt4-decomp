typedef unsigned int u32;

extern "C" void RaceDisplayEventBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5FC0;

extern int D_0088F3B0;

extern "C" void *RaceDisplayInformationEvent__tf(void) {
    if (D_0088F3B0 == 0) {
        RaceDisplayEventBase__tf();
        func_005BFB68(&D_0088F3B0, ((char *)"27RaceDisplayInformationEvent"), &D_006D5FC0);
    }
    return &D_0088F3B0;
}
