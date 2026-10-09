struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *hObject__structor_0(struct Derived *self);
extern "C" char mGameStats__vtable[];
extern "C" struct Derived *mGameStats__structor_1(struct Derived *self)
{
    struct Derived *r = hObject__structor_0(self);
    self->vtbl = mGameStats__vtable;
    return r;
}
