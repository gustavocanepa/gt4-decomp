struct Cond { char pad[0xF884]; short lap; unsigned char done; };
extern "C" int func_0034C1B0(Cond *self);

extern "C" int DynamicsConductorSinglePlayer__virtual_09(Cond *self)
{
    int r = func_0034C1B0(self); if (r == 1) { short lap = self->lap; int fin = !self->done; if (lap < 0) r = fin; } return r;
}
