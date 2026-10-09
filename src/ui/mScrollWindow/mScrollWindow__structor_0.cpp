typedef int s32;

extern void *mScrollWindow__vtable;
extern "C" void *mComposite__structor_0(void *);
extern "C" void *func_002D1B38(void *, s32, void *);

extern "C" void mScrollWindow__structor_0(void *arg0) {
    mComposite__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &mScrollWindow__vtable;
    *(float *)((char *)arg0 + 0xb4) = 0.299999989569f;
    *(void **)((char *)arg0 + 0xb0) = (void *)(0x1);
    *(void **)((char *)arg0 + 0xb8) = 0x0;
    *(void **)((char *)arg0 + 0xbc) = 0x0;
    *(void **)((char *)arg0 + 0xc0) = 0x0;
    func_002D1B38((char *)arg0 + 0xc4, 0x1, (char *)arg0 + 0xfc);
    func_002D1B38((char *)arg0 + 0xfc, 0x0, (char *)arg0 + 0xc4); return;
}
