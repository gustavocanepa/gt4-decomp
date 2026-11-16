/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *, int); };
extern "C" void RaceBase__setReplayEndingFrames(void *, int);
extern "C" void *RaceSolitaire__getInput(void *) throw();
extern "C" char *func_00346A28(void *);
extern "C" void *__dynamic_cast_2(void *, void *, int, void *, void *, void *);
extern char RaceDisplay__tf[];
extern char RaceDisplayBase__tf[];
extern "C" void RaceSolitaire__setReplayEndingFrames(char *self, int frames) {
    char *target = 0;
    RaceBase__setReplayEndingFrames(self, frames);
    char *p = *(char **)(self + 0xe420);
    *(float *)(self + 0xcf54) = -0.5f;
    if (p) {
        char *v = *(char **)p;
        target = (char *)__dynamic_cast_2(*(void **)(v + 4), RaceDisplay__tf, 0, p + *(short *)v, RaceDisplayBase__tf, p);
    }
    char *record = func_00346A28((char *)RaceSolitaire__getInput(self) + 0xd4);
    if (target && record) {
        VEntry *e = (VEntry *)(*(char **)target + 0x170);
        e->fn(target + e->delta, *(int *)(record + 0x10));
    }
}
