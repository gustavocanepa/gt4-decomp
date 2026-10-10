extern int RaceCarSound__visual_;
extern "C" float RaceCarSound__getMasterVolume(void);
extern "C" void SystemSoundPlay(void *a, void *b, void *c, int limit, float x, float y);

extern "C" void RaceSoundPlay(void *a, void *b, void *c, float x, float y) {
    if (RaceCarSound__visual_ == 0)
        SystemSoundPlay(a, b, c, 0x7FFFFFFF, x * RaceCarSound__getMasterVolume(), y);
}
