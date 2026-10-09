typedef int s32;

extern void *D_0064C4AC;
extern void *D_00650000;
extern void *D_00654D8C;
extern void *mpegif__vtable;
extern "C" void func_00574EE8(void *);
extern "C" void func_00578908(void *);
extern "C" void func_0054F7A0(void *);
extern "C" void func_00575DA0(void *);
extern "C" void func_005633A8(void);
extern "C" void func_005ADCB0(void *);
extern "C" void func_00578E98(void *, s32);
extern "C" void func_00574DA8(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void mpegif__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x408) = &mpegif__vtable;
    *(void **)((char *)arg0 + 0x3e4) = 0x0;
    func_00574EE8((char *)arg0 + 0x320);
    func_00578908(*(void **)((char *)arg0 + 0x3cc));
    func_0054F7A0(*(void **)((char *)arg0 + 0x3e8));
    func_00575DA0(*(void **)((char *)arg0 + 0x3d4));
    func_00575DA0(*(void **)((char *)arg0 + 0x3d8));
    func_00575DA0(*(void **)((char *)arg0 + 0x3dc));
    if (*(void **)((char *)&D_00650000 + -0x3b58) == 0) {
        func_005633A8();
    }
    func_005ADCB0(*(void **)(&D_0064C4AC));
    *(void **)(&D_0064C4AC) = (void *)(-0x1);
    func_005ADCB0(*(void **)((char *)arg0 + 0x400));
    *(void **)((char *)arg0 + 0x400) = (void *)(-0x1);
    func_005ADCB0(*(void **)(&D_00654D8C));
    *(void **)(&D_00654D8C) = (void *)(-0x1);
    func_00578E98((char *)arg0 + 0x380, 0x2);
    func_00574DA8((char *)arg0 + 0x350, 0x2);
    func_00574DA8((char *)arg0 + 0x320, 0x2);
    func_00574DA8((char *)arg0 + 0x2f0, 0x2);
    func_00574DA8((char *)arg0 + 0x2c0, 0x2);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
