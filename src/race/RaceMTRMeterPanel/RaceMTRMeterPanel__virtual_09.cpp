struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, float);
};

struct Meter {
    char pad0[0x14];
    VEntry *vt;
    char pad18[0x58];
};

struct RaceMTRMeterPanel {
    char pad0[0x20];
    Meter meters[4];
};

extern "C" void RaceMTRMeterPanel__virtual_09(RaceMTRMeterPanel *self, float t)
{
    Meter *m = self->meters;
    for (int i = 0; i < 4; i++, m++) {
        VEntry *e = &m->vt[10];
        e->fn((char *)m + e->delta, t);
    }
}
