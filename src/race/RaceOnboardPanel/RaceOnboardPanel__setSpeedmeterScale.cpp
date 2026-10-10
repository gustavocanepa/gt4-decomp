typedef int s32;

extern "C" void RaceOnboardSpeedmeter__setSpeedScale(s32 arg0);

extern "C" void RaceOnboardPanel__setSpeedmeterScale(s32 arg0) {
    RaceOnboardSpeedmeter__setSpeedScale(arg0 + 0x6C);
}
