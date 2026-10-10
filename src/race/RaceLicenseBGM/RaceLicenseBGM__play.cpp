typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct Obj {
    int unk0;
    VEntry *vtbl;
    char pad8[0x11E8 - 8];
    int busy;
};

extern "C" void RaceBGMPS2__play(Obj *self, int event, int arg);

extern "C" void RaceLicenseBGM__play(Obj *self, int event, int arg) {
    if (self->busy == 0) {
        if (event == 12) {
            VEntry *e = &self->vtbl[8];
            e->fn((char *)self + e->delta);
        } else {
            RaceBGMPS2__play(self, event, arg);
        }
    }
}
