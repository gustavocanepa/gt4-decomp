struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *hObject__structor_0(struct Derived *self);
extern "C" char mStorageEntry__vtable[];
extern "C" struct Derived *mStorageEntry__structor_0(struct Derived *self)
{
    struct Derived *r = hObject__structor_0(self);
    self->vtbl = mStorageEntry__vtable;
    return r;
}
