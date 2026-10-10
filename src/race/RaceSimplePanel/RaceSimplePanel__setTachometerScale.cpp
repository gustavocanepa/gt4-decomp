typedef int s32;

extern "C" void RaceMeterBase__setScale(s32 arg0);

extern "C" void RaceSimplePanel__setTachometerScale(s32 arg0) {
    RaceMeterBase__setScale(arg0 + 0x100);
}
