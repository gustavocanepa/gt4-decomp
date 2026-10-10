typedef int s32;

extern "C" void RaceTireWearDisplay__setTireWearColor(s32 arg0);

extern "C" void RaceOnboardPanel__setTireWearColor(s32 arg0) {
    RaceTireWearDisplay__setTireWearColor(arg0 + 0xB0C);
}
