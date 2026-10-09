typedef int s32;

extern void *RaceIndicator__vtable;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void *func_003A9608(void *);
extern "C" void *func_003A96F8(void *, float, float);
extern "C" void *func_003A9708(void *, float, float);
extern "C" void *func_003A9738(void *, s32, s32);

extern "C" void RaceIndicator__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    *(void **)((char *)arg0 + 0x14) = &RaceIndicator__vtable;
    func_003A9608((char *)arg0 + 0x18);
    *(void **)((char *)arg0 + 0x38) = (void *)(-0x7f000001);
    *(void **)((char *)arg0 + 0x3c) = 0x0;
    *(char *)((char *)arg0 + 0x40) = 0x0;
    func_003A96F8((char *)arg0 + 0x18, 0.199999991804f, 0.500000014901f);
    func_003A9708((char *)arg0 + 0x18, 0.0f, 0.0699999947101f);
    func_003A9738((char *)arg0 + 0x18, -0x1, 0x0); return;
}
