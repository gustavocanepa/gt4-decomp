struct Obj {
    int value;
    int unk4;
    int *current;
    char padC[0x24 - 0xC];
    int normal;
    char pad28[0x3C - 0x28];
    int override_;
    char pad40[0x54 - 0x40];
    int saved;
    int saved2;
};

extern "C" void RaceSolitaireEntry__changeLoggerMode(Obj *self, int enable) {
    if (enable) {
        int v = self->value;
        self->saved = v;
        if (self->saved2 == 0)
            self->saved2 = v != 0;
        self->value = self->saved2;
        self->override_ = self->normal;
        self->current = &self->override_;
    } else {
        self->saved2 = self->value;
        self->value = self->saved;
        self->current = &self->normal;
    }
}
