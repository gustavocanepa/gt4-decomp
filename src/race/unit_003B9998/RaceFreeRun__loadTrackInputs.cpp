struct Obj {
    char pad[0xF0F8];
    int ready;
};

extern "C" void RaceSolitaire__loadReplaceData(Obj *o, void *x);
extern "C" void RaceSolitaire__loadReplaceInputs(Obj *o, void *x, int a);
extern "C" void RaceSolitaire__loadTrackInputs_2(Obj *o, int mode, void *x);

extern "C" void RaceFreeRun__loadTrackInputs(Obj *o, int mode, void *x) {
    if (mode == 0) {
        RaceSolitaire__loadReplaceData(o, x);
        RaceSolitaire__loadReplaceInputs(o, x, 0);
        o->ready = 1;
    } else {
        RaceSolitaire__loadTrackInputs_2(o, mode, x);
    }
}
