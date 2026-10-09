typedef int s32;
typedef float f32;

struct Obj {
    char pad[0xC8];
    s32 unkC8;
    char pad2[0xD8 - 0xC8 - 4];
    f32 unkD8;
    f32 unkDC;
};

extern "C" void mRaceCourseMapFacePS2__virtual_97(struct Obj *arg0, f32 fparg0, f32 fparg1) {
    if (arg0->unkC8 != 0) {
        arg0->unkD8 = fparg0;
        arg0->unkDC = fparg1;
    }
}
