struct Obj { char pad[0x3C]; int slots[8]; };
extern "C" int Pitmen__isValid(Obj *self, int i);
extern "C" int Pitmen__isRenderPitmenPeriod(Obj *self, int i);

extern "C" int Pitmen__isNotRenderOthersPeriod(Obj *self, int i)
{
    if (!Pitmen__isValid(self, i)) return 0; if (!Pitmen__isRenderPitmenPeriod(self, i)) return 0; return self->slots[i] == 0;
}
