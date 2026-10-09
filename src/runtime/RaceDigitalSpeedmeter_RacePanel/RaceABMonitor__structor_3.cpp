typedef int s32;

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, s32);
};

extern void *RaceSimplePanel__vtable;
extern void *RaceIndicator__vtable;
extern void *RaceSideGravityMeter__vtable;
extern void *RaceABMonitor__vtable;
extern void *RaceShiftTimingLampDisplay__vtable;
extern void *RaceSuggestedGearDisplay__vtable;
extern void *RaceShiftPositionDisplay__vtable;
extern void *RaceMeterBase__vtable;
extern void *RaceTireWearDisplay__vtable;
extern void *RaceFuelMeter__vtable;
extern void *RaceDigitalSpeedmeter__vtable;
extern void *RacePanel__vtable;
extern "C" void RaceDisplayObjectBase__structor_1(void *, s32);
extern "C" void RaceTexturePanel__structor_1(void *, s32);
extern "C" void func_005C1628(void *);

static inline void destroy(char *m, void *vtbl) {
    *(void **)(m + 0x14) = vtbl;
    RaceDisplayObjectBase__structor_1(m, 0);
}

static inline void ab_monitor(char *m) {
    *(void **)(m + 0x14) = &RaceABMonitor__vtable;
    if (m + 0x20 != 0) {
        char *p0 = m + 0x80;
        while (m + 0x20 != p0) {
            VEntry *e;
            p0 -= 0x30;
            e = (VEntry *)(*(char **)(p0 + 0x14) + 0x8);
            e->fn(p0 + e->delta, 2);
        }
    }
    RaceDisplayObjectBase__structor_1(m, 0);
}

extern "C" void RaceABMonitor__structor_3(void *arg0, s32 arg1) {
    char *self = (char *)arg0;
    *(void **)(self + 0x14) = &RaceSimplePanel__vtable;
    destroy(self + 0x344, &RaceIndicator__vtable);
    destroy(self + 0x300, &RaceIndicator__vtable);
    destroy(self + 0x2bc, &RaceIndicator__vtable);
    destroy(self + 0x290, &RaceSideGravityMeter__vtable);
    ab_monitor(self + 0x210);
    destroy(self + 0x1d4, &RaceShiftTimingLampDisplay__vtable);
    destroy(self + 0x17c, &RaceSuggestedGearDisplay__vtable);
    destroy(self + 0x124, &RaceShiftPositionDisplay__vtable);
    destroy(self + 0x100, &RaceMeterBase__vtable);
    destroy(self + 0xd0, &RaceTireWearDisplay__vtable);
    destroy(self + 0xa8, &RaceFuelMeter__vtable);
    destroy(self + 0x80, &RaceFuelMeter__vtable);
    destroy(self + 0x48, &RaceDigitalSpeedmeter__vtable);
    RaceTexturePanel__structor_1(self + 0x2c, 2);
    *(void **)(self + 0x14) = &RacePanel__vtable;
    RaceDisplayObjectBase__structor_1(self, 0);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(self);
    }
}
