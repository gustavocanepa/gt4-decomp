struct Obj { char pad[0xB4]; int count[8]; };
extern "C" int Pitmen__isValid(Obj *self, int i);
extern "C" int Pitmen__isPitCameraPeriod(Obj *self, int i);

extern "C" int Pitmen__isRenderPitmenPeriod(Obj *self, int i)
{
    if (!Pitmen__isValid(self, i))
        return 0;
    if (!Pitmen__isPitCameraPeriod(self, i))
        return 0;
    int *c = self->count; if (c[i] < 5) return 0; return 1;
}
