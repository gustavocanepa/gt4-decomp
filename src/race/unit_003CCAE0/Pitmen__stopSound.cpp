typedef int s32;

extern "C" void RaceSoundStop(s32 arg0, s32 arg1);

extern "C" void Pitmen__stopSound(s32 arg0) {
    RaceSoundStop(arg0 + 0x98E8, 1);
}
