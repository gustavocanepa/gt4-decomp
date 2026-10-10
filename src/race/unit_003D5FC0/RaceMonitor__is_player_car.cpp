typedef int s32;

struct Obj {
    char pad[0x60];
    s32 unk60;
    s32 unk64;
};

extern "C" s32 RaceMonitor__is_player_car(Obj *arg0) {
    return arg0->unk64 == arg0->unk60;
}
