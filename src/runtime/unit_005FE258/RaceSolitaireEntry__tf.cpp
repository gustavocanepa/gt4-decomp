typedef unsigned int u32;

extern "C" void func_005F39A8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F040;

extern int D_0088F8E0;

extern "C" void *RaceSolitaireEntry__tf(void) {
    if (D_0088F8E0 == 0) {
        func_005F39A8();
        func_005BFB68(&D_0088F8E0, ((char *)"18RaceSolitaireEntry"), &D_0088F040);
    }
    return &D_0088F8E0;
}
