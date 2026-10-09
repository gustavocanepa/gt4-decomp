typedef int s32;

extern "C" void mData__structor_1(void *arg0, s32 arg1);
extern "C" void func_00575DA0(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mModelMotion__vtable;

extern "C" void mModelMotion__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mModelMotion__vtable;
    if (*(void **)((char *)arg0 + 0xC) != 0) {
        void *p = *(void **)((char *)arg0 + 0x8);
        *(void **)((char *)arg0 + 0x8) = 0;
        func_00575DA0(p);
    }
    mData__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x24, 4, "RefCounter");
    }
}
