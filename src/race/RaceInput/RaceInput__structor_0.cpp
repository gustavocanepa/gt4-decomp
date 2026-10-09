typedef int s32;

extern void *RaceInput__vtable;
extern "C" void *func_0055F620(void *);
extern "C" void *func_00346758(void *);
extern "C" void *func_0043A0C0(void *, void *);
extern "C" void *func_0043A078(void *);

extern "C" void RaceInput__structor_0(void *arg0) {
    func_0055F620(arg0);
    *(void **)((char *)arg0 + 0xd0) = &RaceInput__vtable;
    func_00346758((char *)arg0 + 0xd4);
    func_0043A0C0((char *)arg0 + 0x170, (char *)arg0 + 0x150);
    func_0043A078((char *)arg0 + 0x1a0);
    *(void **)((char *)arg0 + 0x1c4) = 0x0;
    *(void **)((char *)arg0 + 0x1cc) = (void *)(0x1);
    *(void **)((char *)arg0 + 0x1c8) = 0x0;
    *(void **)((char *)arg0 + 0x1d0) = 0x0;
    *(void **)((char *)arg0 + 0x1d4) = 0x0;
    *(void **)((char *)arg0 + 0x144) = 0x0;
    *(void **)((char *)arg0 + 0x148) = 0x0;
    *(void **)((char *)arg0 + 0x14c) = 0x0;
    *(void **)((char *)arg0 + 0x194) = 0x0;
    *(void **)((char *)arg0 + 0x19c) = 0x0;
    *(void **)((char *)arg0 + 0x1d8) = 0x0;
    *(void **)((char *)arg0 + 0x1dc) = 0x0;
}
