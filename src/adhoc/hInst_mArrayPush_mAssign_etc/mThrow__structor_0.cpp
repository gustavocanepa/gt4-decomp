struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *RefCounter__structor_0(struct Derived *self);
extern "C" char mThrow__vtable[];
extern "C" struct Derived *mThrow__structor_0(struct Derived *self)
{
    struct Derived *r = RefCounter__structor_0(self);
    self->vtbl = mThrow__vtable;
    return r;
}
