typedef unsigned int u32;

extern "C" void RaceInput__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F1A8[];
extern int D_0088FB10;

extern int D_0088EF80;

extern "C" void *RaceInputLan__tf(void) {
    if (D_0088EF80 == 0) {
        RaceInput__tf();
        func_005BFB68(&D_0088EF80, D_0069F1A8, &D_0088FB10);
    }
    return &D_0088EF80;
}
