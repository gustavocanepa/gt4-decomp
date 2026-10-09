typedef int s32;

extern "C" void func_0027AEB0(void *arg0);
extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mBlockTransition__vtable;
extern void *mTransition__vtable;

extern "C" void mTransition__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mBlockTransition__vtable;
    func_0027AEB0(arg0);
    *(void **)((char *)arg0 + 4) = &mTransition__vtable;
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x3C, 4, "RefCounter");
    }
}
