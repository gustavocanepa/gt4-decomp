struct Cond { char pad[0xF884]; short lap; unsigned char done; };
extern "C" int DynamicsConductor__getStartingFormat(Cond *self);

extern "C" int DynamicsConductorSinglePlayer__getStartingFormat(Cond *self)
{
    int r = DynamicsConductor__getStartingFormat(self); if (r == 1) { short lap = self->lap; int fin = !self->done; if (lap < 0) r = fin; } return r;
}
