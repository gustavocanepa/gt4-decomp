struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0030A6B0(struct Derived *self);
extern "C" char D_00674D98[];
extern "C" struct Derived *func_00308B10(struct Derived *self)
{
    struct Derived *r = func_0030A6B0(self);
    self->vtbl = D_00674D98;
    return r;
}
