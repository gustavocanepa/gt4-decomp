typedef int s32;

extern void *RaceSteeringDisplay__vtable;
extern "C" void RaceDisplayObjectBase__structor_0(void *);

extern "C" void RaceSteeringDisplay__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    *(void **)((char *)arg0 + 0x14) = &RaceSteeringDisplay__vtable;
    *(float *)((char *)arg0 + 0x20) = *(float *)((char *)"GTMODE_MACHINE_TEST_MAX_SPEED" + 0x14c0);
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    *(void **)((char *)arg0 + 0x18) = 0x0;
}
