typedef unsigned int u32;

extern "C" void mDefine__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088EDF0;

extern int D_0088EDB0;

extern "C" void *mLocalDefine__tf(void) {
    if (D_0088EDB0 == 0) {
        mDefine__tf();
        func_005BFB68(&D_0088EDB0, ((char *)"12mLocalDefine"), &D_0088EDF0);
    }
    return &D_0088EDB0;
}
