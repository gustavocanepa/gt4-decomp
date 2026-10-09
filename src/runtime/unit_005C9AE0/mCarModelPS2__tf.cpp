typedef unsigned int u32;

extern "C" void mCarModel__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088DB40;

extern int D_0088DB70;

extern "C" void *mCarModelPS2__tf(void) {
    if (D_0088DB70 == 0) {
        mCarModel__tf();
        func_005BFB68(&D_0088DB70, ((char *)"12mCarModelPS2"), &D_0088DB40);
    }
    return &D_0088DB70;
}
