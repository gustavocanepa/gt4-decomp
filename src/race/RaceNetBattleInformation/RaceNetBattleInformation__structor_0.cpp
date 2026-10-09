typedef int s32;

extern void *D_00640000;
extern void *RaceNetBattleInformation__vtable;
extern "C" void *func_005F30A0(void *);

extern "C" void RaceNetBattleInformation__structor_0(void *arg0) {
    func_005F30A0(arg0);
    *(void **)((char *)arg0 + 0xab8) = (void *)(-0x1);
    *(void **)((char *)arg0 + 0x12c) = &RaceNetBattleInformation__vtable;
    *(void **)((char *)arg0 + 0x118) = *(void **)((char *)&D_00640000 + 0x6450);
}
