struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *mDefine__structor_0(struct Derived *self);
extern "C" char mLocalDefine__vtable[];
extern "C" struct Derived *mLocalDefine__structor_0(struct Derived *self)
{
    struct Derived *r = mDefine__structor_0(self);
    self->vtbl = mLocalDefine__vtable;
    return r;
}
