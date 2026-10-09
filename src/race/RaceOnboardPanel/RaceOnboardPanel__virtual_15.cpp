typedef int s32;

extern "C" void RaceOnboardTachometer__virtual_09(s32 arg0);

extern "C" void RaceOnboardPanel__virtual_15(s32 arg0) {
    RaceOnboardTachometer__virtual_09(arg0 + 0xC8);
}
