typedef int s32;

extern void *RaceRefuelMeter__vtable;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);

extern "C" void *RaceRefuelMeter__structor_1(void *arg0) {
    void *r0 = RaceDisplayObjectBase__structor_0(arg0);
    *(void **)((char *)arg0 + 0x18) = 0x0;
    *(void **)((char *)arg0 + 0x14) = &RaceRefuelMeter__vtable;
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    *(void **)((char *)arg0 + 0x20) = 0x0;
    *(void **)((char *)arg0 + 0x24) = 0x0;
    return r0;
}
