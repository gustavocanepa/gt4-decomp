typedef unsigned int u32;

extern "C" void func_005FAFC0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5FE0;

extern int D_0088F6B0;

extern "C" void *RaceEntryInformation__tf(void) {
    if (D_0088F6B0 == 0) {
        func_005FAFC0();
        func_005BFB68(&D_0088F6B0, ((char *)"20RaceEntryInformation"), &D_006D5FE0);
    }
    return &D_0088F6B0;
}
