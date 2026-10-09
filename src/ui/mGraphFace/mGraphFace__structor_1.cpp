typedef int s32;

extern void *mGraphFace__vtable;
extern "C" void mColorFace__structor_1(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);

extern "C" void mGraphFace__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x4) = &mGraphFace__vtable;
    mColorFace__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x8c4, 0x4, "RefCounter");
    }
}
