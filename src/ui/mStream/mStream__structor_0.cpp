typedef int s32;

extern void *mStream__vtable;
extern "C" void *hObject__structor_0(void *);

extern "C" void mStream__structor_0(void *arg0) {
    hObject__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &mStream__vtable;
    *(void **)((char *)arg0 + 0x24) = 0x0;
    *(void **)((char *)arg0 + 0x10) = 0x0;
    *(void **)((char *)arg0 + 0x14) = 0x0;
    *(void **)((char *)arg0 + 0x18) = 0x0;
    *(void **)((char *)arg0 + 0x20) = 0x0;
    *(void **)((char *)arg0 + 0x1c) = (void *)(0x1);
}
