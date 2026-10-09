typedef unsigned int u32;

extern "C" void mWatcher__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E370;

extern int D_0088E8B0;

extern "C" void *mScriptWatcher__tf(void) {
    if (D_0088E8B0 == 0) {
        mWatcher__tf();
        func_005BFB68(&D_0088E8B0, ((char *)"14mScriptWatcher"), &D_0088E370);
    }
    return &D_0088E8B0;
}
