struct Sub {
    char pad0[0x28];
    int active;
};

struct Obj {
    int unk0;
    Sub sub;
};

extern "C" int Pitmen__isValid(Obj *self);
extern "C" int Pitmen__Camera__isPitSequence(Sub *sub, int arg);

extern "C" int Pitmen__isPitCameraPeriod(Obj *self, int arg) {
    if (!Pitmen__isValid(self))
        return 0;
    Sub *s = &self->sub;
    if (!s->active)
        return 0;
    return Pitmen__Camera__isPitSequence(s, arg);
}
