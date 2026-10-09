typedef unsigned int u32;

extern "C" void func_005F3410();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F270[];
extern int D_0088EF90;

extern int D_0088EFD0;

extern "C" void *RaceNetBattle__tf(void) {
    if (D_0088EFD0 == 0) {
        func_005F3410();
        func_005BFB68(&D_0088EFD0, D_0069F270, &D_0088EF90);
    }
    return &D_0088EFD0;
}
