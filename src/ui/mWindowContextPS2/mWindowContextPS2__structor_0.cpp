struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *mWindowContext__structor_0(struct Derived *self);
extern "C" char mWindowContextPS2__vtable[];
extern "C" struct Derived *mWindowContextPS2__structor_0(struct Derived *self)
{
    struct Derived *r = mWindowContext__structor_0(self);
    self->vtbl = mWindowContextPS2__vtable;
    return r;
}
