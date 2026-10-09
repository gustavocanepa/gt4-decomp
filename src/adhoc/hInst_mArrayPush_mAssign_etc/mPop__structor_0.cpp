struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *RefCounter__structor_0(struct Derived *self);
extern "C" char mPop__vtable[];
extern "C" struct Derived *mPop__structor_0(struct Derived *self)
{
    struct Derived *r = RefCounter__structor_0(self);
    self->vtbl = mPop__vtable;
    return r;
}
