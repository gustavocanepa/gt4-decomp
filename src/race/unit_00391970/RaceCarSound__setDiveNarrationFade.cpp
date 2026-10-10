extern "C" int RaceCarSound__dive_;
extern "C" int RaceCarSound__narration_;
extern "C" void RaceCarSound__fadeMasterVolume(float scale, float alpha);

extern "C" void RaceCarSound__setDiveNarrationFade(void)
{
    float scale = 1.0f;
    if (RaceCarSound__dive_)
        scale = 0.45f;
    if (RaceCarSound__narration_)
        scale = 0.2f;
    RaceCarSound__fadeMasterVolume(scale, 1.0f);
}
