typedef int s32;

extern void *RaceRankDisplay__vtable;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void *func_003A9758(void *);
extern "C" void *func_003A9850(void *, float);

extern "C" void RaceRankDisplay__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    *(void **)((char *)arg0 + 0x18) = 0x0;
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    *(void **)((char *)arg0 + 0x14) = &RaceRankDisplay__vtable;
    *(void **)((char *)arg0 + 0x20) = 0x0;
    func_003A9758((char *)arg0 + 0x24);
    func_003A9850((char *)arg0 + 0x24, 0.0f); return;
}
