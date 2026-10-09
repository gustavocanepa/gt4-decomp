typedef unsigned int u32;

extern "C" void func_005FDFF8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F870;

extern int D_0088F8A0;

extern "C" void *func_005FE048(void) {
    if (D_0088F8A0 == 0) {
        func_005FDFF8();
        func_005BFB68(&D_0088F8A0, ((char *)"Q29Serialize9TrackData"), &D_0088F870);
    }
    return &D_0088F8A0;
}
