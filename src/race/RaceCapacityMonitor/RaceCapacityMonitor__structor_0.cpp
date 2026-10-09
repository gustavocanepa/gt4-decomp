typedef int s32;

extern void *RaceCapacityMonitor__vtable;
extern "C" void RaceDisplayObjectBase__structor_0(void *);

extern "C" void RaceCapacityMonitor__structor_0(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    void *p0 = *(void **)((char *)arg0 + 0x24);
    *(void **)((char *)arg0 + 0x14) = &RaceCapacityMonitor__vtable;
    *(void **)((char *)arg0 + 0x24) = (void *)(((s32)p0 & (s32)-0x100));
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    *(void **)((char *)arg0 + 0x20) = 0x0;
    *(void **)((char *)arg0 + 0x18) = 0x0;
}
