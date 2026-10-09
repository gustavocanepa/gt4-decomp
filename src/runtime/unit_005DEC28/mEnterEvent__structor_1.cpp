struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *mEvent__structor_0(struct Derived *self);
extern "C" char mEnterEvent__vtable[];
extern "C" struct Derived *mEnterEvent__structor_1(struct Derived *self)
{
    struct Derived *r = mEvent__structor_0(self);
    self->vtbl = mEnterEvent__vtable;
    return r;
}
