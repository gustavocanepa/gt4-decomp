struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *mEyetoyImageProcessor__structor_0(struct Derived *self);
extern "C" char mGTShirt__vtable[];
extern "C" struct Derived *mGTShirt__structor_0(struct Derived *self)
{
    struct Derived *r = mEyetoyImageProcessor__structor_0(self);
    self->vtbl = mGTShirt__vtable;
    return r;
}
