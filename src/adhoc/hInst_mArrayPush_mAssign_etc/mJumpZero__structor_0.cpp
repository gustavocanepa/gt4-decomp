typedef int s32;

extern void *mJumpZero__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mJumpZero__structor_0(void *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &mJumpZero__vtable;
    *(void **)((char *)arg0 + 0x8) = (void *)(arg1);
    return r0;
}
