struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0030A678(struct Derived *self);
extern "C" char D_00674D98[];
extern "C" struct Derived *func_00308AE0(struct Derived *self)
{
    struct Derived *r = func_0030A678(self);
    self->vtbl = D_00674D98;
    return r;
}
