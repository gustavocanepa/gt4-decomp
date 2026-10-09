struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *mEyetoyFace__structor_0(struct Derived *self);
extern "C" char mEyetoyFacePS2__vtable[];
extern "C" struct Derived *mEyetoyFacePS2__structor_0(struct Derived *self)
{
    struct Derived *r = mEyetoyFace__structor_0(self);
    self->vtbl = mEyetoyFacePS2__vtable;
    return r;
}
