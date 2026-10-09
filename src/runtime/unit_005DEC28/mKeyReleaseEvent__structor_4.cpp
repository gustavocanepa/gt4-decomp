typedef int s32;

extern void *mKeyReleaseEvent__vtable;
extern "C" void *mWindowEvent__structor_0(void *);

extern "C" void *mKeyReleaseEvent__structor_4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, float farg0, float farg1) {
    void *r0 = mWindowEvent__structor_0(arg0);
    *(void **)((char *)arg0 + 0x20) = (void *)(arg3);
    *(void **)((char *)arg0 + 0x24) = (void *)(arg4);
    *(float *)((char *)arg0 + 0x28) = farg0;
    *(float *)((char *)arg0 + 0x2c) = farg1;
    *(void **)((char *)arg0 + 0x4) = &mKeyReleaseEvent__vtable;
    return r0;
}
