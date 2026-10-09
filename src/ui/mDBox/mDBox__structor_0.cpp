typedef int s32;

extern void *mDBox__vtable;
extern "C" void *mBox__structor_0(void *);

extern "C" void *mDBox__structor_0(void *arg0, s32 arg1) {
    void *r0 = mBox__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &mDBox__vtable;
    *(void **)((char *)arg0 + 0xcc) = 0x0;
    *(void **)((char *)arg0 + 0xc0) = 0x0;
    *(void **)((char *)arg0 + 0xc8) = 0x0;
    *(void **)((char *)arg0 + 0xc4) = (void *)(arg1);
    return r0;
}
