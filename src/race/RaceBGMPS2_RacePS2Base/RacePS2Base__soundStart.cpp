typedef int s32;

extern "C" void RaceBase__soundStart(void *arg0);
extern "C" void RaceCourseSound__playStart(s32 *arg0);
extern "C" void Pitmen__playSound(void *arg0);

extern "C" void RacePS2Base__soundStart(void *arg0) {
    RaceBase__soundStart(arg0);
    RaceCourseSound__playStart((s32 *)((char *)arg0 + 0xE170));
    Pitmen__playSound((char *)arg0 + 0x3628);
}
