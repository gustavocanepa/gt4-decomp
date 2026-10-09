struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *RaceDisplayDiffEvent__structor_0(struct Derived *self);
extern "C" char RaceDisplayLapDiffEvent__vtable[];
extern "C" struct Derived *RaceDisplayLapDiffEvent__structor_3(struct Derived *self)
{
    struct Derived *r = RaceDisplayDiffEvent__structor_0(self);
    self->vtbl = RaceDisplayLapDiffEvent__vtable;
    return r;
}
