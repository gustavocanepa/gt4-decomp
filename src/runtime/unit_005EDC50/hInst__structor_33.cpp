struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *RefCounter__structor_0(struct Derived *self);
extern "C" char hInst__vtable[];
extern "C" struct Derived *hInst__structor_33(struct Derived *self)
{
    struct Derived *r = RefCounter__structor_0(self);
    self->vtbl = hInst__vtable;
    return r;
}
