typedef int s32;
typedef float f32;

extern "C" void RaceRoundTachometerBase__setRedZone(void *arg0, f32 arg1);

extern "C" void RaceOnboardPanel__setTachometerRedZone(void *arg0, s32 arg1) {
    RaceRoundTachometerBase__setRedZone((char *)arg0 + 0xC8, (f32)arg1);
}
