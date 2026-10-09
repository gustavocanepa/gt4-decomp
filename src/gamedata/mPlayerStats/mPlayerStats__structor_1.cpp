struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *hObject__structor_0(struct Derived *self);
extern "C" char mPlayerStats__vtable[];
extern "C" struct Derived *mPlayerStats__structor_1(struct Derived *self)
{
    struct Derived *r = hObject__structor_0(self);
    self->vtbl = mPlayerStats__vtable;
    return r;
}
