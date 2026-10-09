struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *RefCounter__structor_0(struct Derived *self);
extern "C" char mRequire__vtable[];
extern "C" struct Derived *mRequire__structor_0(struct Derived *self)
{
    struct Derived *r = RefCounter__structor_0(self);
    self->vtbl = mRequire__vtable;
    return r;
}
