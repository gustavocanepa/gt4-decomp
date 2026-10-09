typedef int s32;

extern "C" void func_00575DA0(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_002F9B38(void *, s32);
extern "C" void mScrollable__structor_1(void *, s32);

extern void *mSelectBox__vtable;

extern "C" void mSelectBox__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mSelectBox__vtable;
    void *p = *(void **)((char *)arg0 + 0xF0);
    if (p != 0) {
        *(void **)((char *)arg0 + 0xF0) = 0;
        func_00575DA0(p);
    }
    func_002F9B38((char *)arg0 + 0xF4, 2);
    mScrollable__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xFC, 4, "RefCounter");
    }
}
