struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_00200C08(struct Derived *self);
extern "C" char D_0066AF28[];
extern "C" struct Derived *func_0028F6C8(struct Derived *self)
{
    struct Derived *r = func_00200C08(self);
    self->vtbl = D_0066AF28;
    return r;
}
