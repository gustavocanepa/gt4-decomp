typedef int s32;

struct Obj {
    char pad[0x14];
    s32 unk14;
};

extern "C" void RaceEntryCar__setPlayerSpec(struct Obj *arg0, void *arg1);

extern "C" void RaceSinglePlayerInformation__updateEntryCar(void *arg0, struct Obj *arg1) {
    if (arg1->unk14 == 0) {
        RaceEntryCar__setPlayerSpec(arg1, (char *)arg0 + 0x130);
    }
}
