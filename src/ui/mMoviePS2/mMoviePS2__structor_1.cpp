typedef int s32;

extern void *D_00618E40;
extern void *mMoviePS2__vtable;
extern "C" void func_001FE510(void *);
extern "C" void func_001FD5E8(void *);
extern "C" void mMovie__structor_1(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);

extern "C" void mMoviePS2__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x4) = &mMoviePS2__vtable;
    func_001FE510(&D_00618E40);
    func_001FD5E8(&D_00618E40);
    mMovie__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x14, 0x4, "RefCounter");
    }
}
