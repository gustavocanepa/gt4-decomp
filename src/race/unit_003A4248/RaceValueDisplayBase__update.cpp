typedef int s32;

struct RaceValueDisplay;

extern "C" void AutomaticFader__update(RaceValueDisplay *arg0, float arg1);

extern "C" void RaceValueDisplayBase__update(char *arg0) {
    AutomaticFader__update((RaceValueDisplay *)(arg0 + 0x28), 0.016666667f);
}
