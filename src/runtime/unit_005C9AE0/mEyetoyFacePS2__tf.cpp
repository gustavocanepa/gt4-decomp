typedef unsigned int u32;

extern "C" void mEyetoyFace__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088DDA0;

extern int D_0088DDF0;

extern "C" void *mEyetoyFacePS2__tf(void) {
    if (D_0088DDF0 == 0) {
        mEyetoyFace__tf();
        func_005BFB68(&D_0088DDF0, ((char *)"14mEyetoyFacePS2"), &D_0088DDA0);
    }
    return &D_0088DDF0;
}
