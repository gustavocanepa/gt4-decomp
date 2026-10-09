struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *RefCounter__structor_0(struct Derived *self);
extern "C" char mMovie__vtable[];
extern "C" struct Derived *mMovie__structor_0(struct Derived *self)
{
    struct Derived *r = RefCounter__structor_0(self);
    self->vtbl = mMovie__vtable;
    return r;
}
