typedef unsigned int u32;

extern "C" void mDefine__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088EDF0;

extern int D_0088EDE0;

extern "C" void *mMethodDefine__tf(void) {
    if (D_0088EDE0 == 0) {
        mDefine__tf();
        func_005BFB68(&D_0088EDE0, ((char *)"13mMethodDefine"), &D_0088EDF0);
    }
    return &D_0088EDE0;
}
