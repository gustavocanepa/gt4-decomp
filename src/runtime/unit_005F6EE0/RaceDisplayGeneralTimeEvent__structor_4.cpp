struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *RaceDisplayDiffEvent__structor_0(struct Derived *self);
extern "C" char RaceDisplayGeneralTimeEvent__vtable[];
extern "C" struct Derived *RaceDisplayGeneralTimeEvent__structor_4(struct Derived *self)
{
    struct Derived *r = RaceDisplayDiffEvent__structor_0(self);
    self->vtbl = RaceDisplayGeneralTimeEvent__vtable;
    return r;
}
