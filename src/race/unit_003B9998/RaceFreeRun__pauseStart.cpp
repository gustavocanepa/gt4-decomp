typedef int s32;

struct Obj {
    char pad[0xE418];
    s32 active;
};

extern "C" void RaceBasic__pauseStart(Obj *);
extern "C" void RaceFreeRun__setDescriptionVoicePause(Obj *, s32);

extern "C" void RaceFreeRun__pauseStart(Obj *self) {
    RaceBasic__pauseStart(self);
    if (self->active != 0)
        RaceFreeRun__setDescriptionVoicePause(self, 1);
}
