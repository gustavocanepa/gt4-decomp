typedef int s32;

extern "C" void func_00575DA0(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void mModelSet__structor_1(void *, s32);

extern void *mModelSetPS2__vtable;

extern "C" void mModelSetPS2__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mModelSetPS2__vtable;
    if (*(void **)((char *)arg0 + 0xC) != 0) {
        func_00575DA0(*(void **)((char *)arg0 + 8));
    }
    mModelSet__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
