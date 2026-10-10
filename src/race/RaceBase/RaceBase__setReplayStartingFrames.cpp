typedef int s32;

struct Obj {
    char pad[0xD50];
    s32 unkD50;
};

extern "C" void RaceBase__setReplayStartingFrames(Obj *arg0, s32 arg1) {
    if (arg1 <= 0) {
        arg1 = 0;
    }
    arg0->unkD50 = arg1 * 0x3C;
}
