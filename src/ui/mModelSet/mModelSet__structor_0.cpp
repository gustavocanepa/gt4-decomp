struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *mData__structor_0(struct Derived *self);
extern "C" char mModelSet__vtable[];
extern "C" struct Derived *mModelSet__structor_0(struct Derived *self)
{
    struct Derived *r = mData__structor_0(self);
    self->vtbl = mModelSet__vtable;
    return r;
}
