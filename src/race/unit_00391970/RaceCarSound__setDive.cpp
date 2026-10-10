typedef int s32;

extern s32 RaceCarSound__dive_;

extern void RaceCarSound__setDiveNarrationFade(void);

void RaceCarSound__setDive(s32 arg0)
{
    RaceCarSound__dive_ = arg0;
    RaceCarSound__setDiveNarrationFade();
}
