struct Obj {
    char pad[0x9290];
    void *items[0xFD];
    int states[8];
};

extern "C" int Pitmen__isValid(Obj *o, int i);
extern "C" int Pitmen__isPitCameraPeriod(Obj *o, int i);

extern "C" int Pitmen__isExtensionPitCameraPeriod(Obj *o, int i) {
    int r = Pitmen__isValid(o, i);
    if (r == 0)
        return r;
    if (o->states[i] == 5 && o->items[i] && !Pitmen__isPitCameraPeriod(o, i))
        return 1;
    return 0;
}
