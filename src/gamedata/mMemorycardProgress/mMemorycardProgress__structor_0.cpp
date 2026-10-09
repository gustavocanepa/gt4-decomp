struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *hObject__structor_0(struct Derived *self);
extern "C" char mMemorycardProgress__vtable[];
extern "C" struct Derived *mMemorycardProgress__structor_0(struct Derived *self)
{
    struct Derived *r = hObject__structor_0(self);
    self->vtbl = mMemorycardProgress__vtable;
    return r;
}
