typedef int s32;

extern void *mNetConfPS2__vtable;
extern "C" void *mNetConf__structor_0(void *);

extern "C" void *mNetConfPS2__structor_0(void *arg0) {
    void *r0 = mNetConf__structor_0(arg0);
    *(void **)((char *)arg0 + 0x268) = 0x0;
    *(void **)((char *)arg0 + 0x4) = &mNetConfPS2__vtable;
    *(void **)((char *)arg0 + 0x26c) = 0x0;
    *(char *)((char *)arg0 + 0x270) = 0x0;
    *(char *)((char *)arg0 + 0x370) = 0x0;
    return r0;
}
