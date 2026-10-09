typedef int s32;

extern void *mNetConf__vtable;
extern "C" void hObject__structor_2(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);

extern "C" void mNetConf__structor_2(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x4) = &mNetConf__vtable;
    hObject__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x268, 0x4, "RefCounter");
    }
}
