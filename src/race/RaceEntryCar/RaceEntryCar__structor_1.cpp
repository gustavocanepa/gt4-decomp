typedef int s32;

extern void *D_0065B7E0;
extern void *RaceEntryCar__vtable;
extern "C" void func_003B4E28(void *, s32);
extern "C" void func_003920A8(void *, s32);
extern "C" void RaceCarModel__structor_1(void *, s32);
extern "C" void RaceLapTime__structor_1(void *, s32);
extern "C" void RaceEntryInformation__structor_1(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void RaceEntryCar__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x35cc) = &RaceEntryCar__vtable;
    func_003B4E28(arg0, 0x1);
    func_003920A8((char *)arg0 + 0x2900, 0x2);
    *(void **)((char *)arg0 + 0x2890) = &D_0065B7E0;
    RaceCarModel__structor_1((char *)arg0 + 0x11f0, 0x2);
    RaceLapTime__structor_1((char *)arg0 + 0x1a0, 0x2);
    RaceEntryInformation__structor_1((char *)arg0 + 0x20, 0x2);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
