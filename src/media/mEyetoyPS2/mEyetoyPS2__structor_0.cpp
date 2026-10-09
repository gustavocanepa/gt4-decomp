typedef int s32;

extern void *mEyetoyPS2__vtable;
extern "C" void *mEyetoy__structor_0(void *);

extern "C" void *mEyetoyPS2__structor_0(void *arg0) {
    void *r0 = mEyetoy__structor_0(arg0);
    *(void **)((char *)arg0 + 0x10) = 0x0;
    *(void **)((char *)arg0 + 0x4) = &mEyetoyPS2__vtable;
    *(void **)((char *)arg0 + 0x14) = 0x0;
    *(void **)((char *)arg0 + 0x18) = 0x0;
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    return r0;
}
