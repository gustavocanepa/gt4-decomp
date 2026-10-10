typedef int s32;

struct Obj_0032FC98 {
    char pad0[0xD80];
    s32 unkD80;
};

extern "C" void RacePS2Base__raceEnd(Obj_0032FC98 *arg0);

extern "C" void RaceSplitBattle__virtual_79(Obj_0032FC98 *arg0) {
    RacePS2Base__raceEnd(arg0);
    arg0->unkD80 = 1;
}
