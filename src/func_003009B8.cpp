struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0030A678(struct Derived *self);
extern "C" char D_00674500[];
extern "C" struct Derived *func_003009B8(struct Derived *self)
{
    struct Derived *r = func_0030A678(self);
    self->vtbl = D_00674500;
    return r;
}
