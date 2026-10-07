struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0030A678(struct Derived *self);
extern "C" char D_0065DAD0[];
extern "C" struct Derived *func_0019C3C0(struct Derived *self)
{
    struct Derived *r = func_0030A678(self);
    self->vtbl = D_0065DAD0;
    return r;
}
