typedef int s32;

extern void *mCallbackEvent__vtable;
extern "C" void *mEvent__structor_0(void *);

extern "C" void *mCallbackEvent__structor_0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *r0 = mEvent__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &mCallbackEvent__vtable;
    *(void **)((char *)arg0 + 0x20) = (void *)(arg3);
    return r0;
}
