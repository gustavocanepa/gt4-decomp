typedef int s32;

struct S { char pad[0x28]; s32 unk28; };

extern "C" s32 RaceMonitor__isFullScreenMode(S *arg0) {
    return arg0->unk28 == 1;
}
