struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *mBox__structor_0(struct Derived *self);
extern "C" char mFBox__vtable[];
extern "C" struct Derived *mFBox__structor_0(struct Derived *self)
{
    struct Derived *r = mBox__structor_0(self);
    self->vtbl = mFBox__vtable;
    return r;
}
