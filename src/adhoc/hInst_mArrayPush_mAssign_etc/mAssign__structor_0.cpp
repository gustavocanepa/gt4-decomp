struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *RefCounter__structor_0(struct Derived *self);
extern "C" char mAssign__vtable[];
extern "C" struct Derived *mAssign__structor_0(struct Derived *self)
{
    struct Derived *r = RefCounter__structor_0(self);
    self->vtbl = mAssign__vtable;
    return r;
}
