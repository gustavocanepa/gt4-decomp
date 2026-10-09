struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *mEvent__structor_0(struct Derived *self);
extern "C" char mCancelEvent__vtable[];
extern "C" struct Derived *mCancelEvent__structor_0(struct Derived *self)
{
    struct Derived *r = mEvent__structor_0(self);
    self->vtbl = mCancelEvent__vtable;
    return r;
}
