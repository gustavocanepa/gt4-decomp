typedef int s32;

extern "C" void Oscillator__update(s32 arg0);

extern "C" void RaceMTRMeter__virtual_09(char *arg0) {
    Oscillator__update((s32)(arg0 + 0x4C));
}
