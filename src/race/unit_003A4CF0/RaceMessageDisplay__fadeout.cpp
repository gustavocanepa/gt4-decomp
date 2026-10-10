typedef int s32;

extern "C" void AutomaticFader__fadeout(s32 arg0);

extern "C" void RaceMessageDisplay__fadeout(s32 arg0) {
    AutomaticFader__fadeout(arg0 + 0x54);
}
