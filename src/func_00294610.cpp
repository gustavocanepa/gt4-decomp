struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0028E8E8(struct Derived *self);
extern "C" char D_0066B7A8[];
extern "C" struct Derived *func_00294610(struct Derived *self)
{
    struct Derived *r = func_0028E8E8(self);
    self->vtbl = D_0066B7A8;
    return r;
}
