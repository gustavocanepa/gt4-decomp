typedef int s32;

extern s32 RaceCarSound__narration_;

extern void RaceCarSound__setDiveNarrationFade(void);

void RaceCarSound__setNarration(s32 arg0)
{
    RaceCarSound__narration_ = arg0;
    RaceCarSound__setDiveNarrationFade();
}
