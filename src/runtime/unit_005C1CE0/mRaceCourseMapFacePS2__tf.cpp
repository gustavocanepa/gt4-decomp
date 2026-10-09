typedef unsigned int u32;

extern "C" void mRaceCourseMapFace__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068E6B0[];
extern int D_0088DAB0;

extern int D_0088DAA0;

extern "C" void *mRaceCourseMapFacePS2__tf(void) {
    if (D_0088DAA0 == 0) {
        mRaceCourseMapFace__tf();
        func_005BFB68(&D_0088DAA0, D_0068E6B0, &D_0088DAB0);
    }
    return &D_0088DAA0;
}
