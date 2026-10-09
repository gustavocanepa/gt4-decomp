typedef int s32;

extern "C" void func_00203118(void *arg0, s32 arg1);
extern "C" void mWidget__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mRaceCourseMapFace__vtable;

extern "C" void mRaceCourseMapFace__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mRaceCourseMapFace__vtable;
    func_00203118((char *)arg0 + 0xB0, 2);
    func_00203118((char *)arg0 + 0xA0, 2);
    mWidget__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xC8, 4, "RefCounter");
    }
}
