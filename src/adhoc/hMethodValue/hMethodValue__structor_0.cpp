struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *hValue__structor_0(struct Derived *self);
extern "C" char hMethodValue__vtable[];
extern "C" struct Derived *hMethodValue__structor_0(struct Derived *self)
{
    struct Derived *r = hValue__structor_0(self);
    self->vtbl = hMethodValue__vtable;
    return r;
}
