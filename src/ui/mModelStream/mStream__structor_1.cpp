typedef int s32;

extern "C" void func_0021C9D8(void *arg0);
extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mModelStream__vtable;
extern void *mStream__vtable;

extern "C" void mStream__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mModelStream__vtable;
    func_0021C9D8(arg0);
    *(void **)((char *)arg0 + 4) = &mStream__vtable;
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x2C, 4, "RefCounter");
    }
}
