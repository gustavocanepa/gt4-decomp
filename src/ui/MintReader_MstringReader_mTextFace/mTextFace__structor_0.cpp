typedef int s32;

extern void *mTextFace__vtable;
extern "C" void *mWidget__structor_0(void *);
extern "C" void *func_00246F58(void *);
extern "C" void *func_002B70B8(void *);
extern "C" void *func_0025B4C8(void *, float, float);

extern "C" void mTextFace__structor_0(void *arg0) {
    mWidget__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &mTextFace__vtable;
    func_00246F58((char *)arg0 + 0xa0);
    func_002B70B8((char *)arg0 + 0x104);
    *(void **)((char *)arg0 + 0x108) = 0x0;
    *(void **)((char *)arg0 + 0x114) = 0x0;
    *(void **)((char *)arg0 + 0x10c) = (void *)(-0x1);
    *(void **)((char *)arg0 + 0x110) = (void *)(-0x1);
    *(void **)((char *)arg0 + 0x118) = 0x0;
    *(void **)((char *)arg0 + 0x11c) = 0x0;
    func_0025B4C8(arg0, 256.000007629f, 24.0000004768f); return;
}
