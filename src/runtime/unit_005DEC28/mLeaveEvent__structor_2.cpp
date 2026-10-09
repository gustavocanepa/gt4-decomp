struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *mEvent__structor_0(struct Derived *self);
extern "C" char mLeaveEvent__vtable[];
extern "C" struct Derived *mLeaveEvent__structor_2(struct Derived *self)
{
    struct Derived *r = mEvent__structor_0(self);
    self->vtbl = mLeaveEvent__vtable;
    return r;
}
