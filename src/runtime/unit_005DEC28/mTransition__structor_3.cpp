typedef int s32;

extern void *mColorTransition__vtable;
extern void *mTransition__vtable;
extern "C" void func_00203118(void *, s32);
extern "C" void hObject__structor_2(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);

extern "C" void mTransition__structor_3(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x4) = &mColorTransition__vtable;
    func_00203118((char *)arg0 + 0x28, 0x2);
    *(void **)((char *)arg0 + 0x4) = &mTransition__vtable;
    hObject__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x38, 0x4, "RefCounter");
    }
}
