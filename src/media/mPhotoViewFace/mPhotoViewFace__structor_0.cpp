struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *mWidget__structor_0(struct Derived *self);
extern "C" char mPhotoViewFace__vtable[];
extern "C" struct Derived *mPhotoViewFace__structor_0(struct Derived *self)
{
    struct Derived *r = mWidget__structor_0(self);
    self->vtbl = mPhotoViewFace__vtable;
    return r;
}
