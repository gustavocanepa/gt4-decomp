struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *mData__structor_0(struct Derived *self);
extern "C" char mImage__vtable[];
extern "C" struct Derived *mImage__structor_0(struct Derived *self)
{
    struct Derived *r = mData__structor_0(self);
    self->vtbl = mImage__vtable;
    return r;
}
