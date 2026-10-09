extern "C" void func_005BFB88(void *a0, void *a1);


extern int D_006D5FE8;

extern "C" void *RaceEntryBase__tf(void) {
    if (D_006D5FE8 == 0) {
        func_005BFB88(&D_006D5FE8, ((char *)"13RaceEntryBase"));
    }
    return &D_006D5FE8;
}
