typedef int s32;

struct Obj {
    char pad[0x958];
    s32 unk958;
};

extern "C" void RaceBase__createReplayInformation(void *arg0);

extern "C" void RaceSolitaire__createReplayInformation(void *arg0, struct Obj *arg1) {
    RaceBase__createReplayInformation(arg0);
    arg1->unk958 = 1;
}
