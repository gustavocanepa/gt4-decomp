struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *RaceDisplayDiffEvent__structor_0(struct Derived *self);
extern "C" char RaceDisplayTimeDiffEvent__vtable[];
extern "C" struct Derived *RaceDisplayTimeDiffEvent__structor_3(struct Derived *self)
{
    struct Derived *r = RaceDisplayDiffEvent__structor_0(self);
    self->vtbl = RaceDisplayTimeDiffEvent__vtable;
    return r;
}
