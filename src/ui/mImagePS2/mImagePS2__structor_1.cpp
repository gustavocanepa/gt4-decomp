typedef int s32;

extern "C" void func_00575DA0(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void mImage__structor_1(void *, s32);

extern void *mImagePS2__vtable;

extern "C" void mImagePS2__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mImagePS2__vtable;
    if (*(void **)((char *)arg0 + 0x20) != 0) {
        void *p = *(void **)((char *)arg0 + 0x14);
        *(void **)((char *)arg0 + 0x14) = 0;
        func_00575DA0(p);
    }
    mImage__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x24, 4, "RefCounter");
    }
}
