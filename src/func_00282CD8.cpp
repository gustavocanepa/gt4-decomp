struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0028E8E8(struct Derived *self);
extern "C" char D_00669AB8[];
extern "C" struct Derived *func_00282CD8(struct Derived *self)
{
    struct Derived *r = func_0028E8E8(self);
    self->vtbl = D_00669AB8;
    return r;
}
