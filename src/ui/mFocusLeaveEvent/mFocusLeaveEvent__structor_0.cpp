struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *mEvent__structor_0(struct Derived *self);
extern "C" char mFocusLeaveEvent__vtable[];
extern "C" struct Derived *mFocusLeaveEvent__structor_0(struct Derived *self)
{
    struct Derived *r = mEvent__structor_0(self);
    self->vtbl = mFocusLeaveEvent__vtable;
    return r;
}
