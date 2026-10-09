typedef int s32;

extern "C" void func_00228480(void *arg0, s32 arg1);
extern "C" void mImageFace__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mProgressFace__vtable;

extern "C" void mProgressFace__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mProgressFace__vtable;
    func_00228480((char *)arg0 + 0xF0, 2);
    mImageFace__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x100, 4, "RefCounter");
    }
}
