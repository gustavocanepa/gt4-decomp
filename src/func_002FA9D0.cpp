struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_00323C10(struct Derived *self);
extern "C" char D_00674090[];
extern "C" struct Derived *func_002FA9D0(struct Derived *self)
{
    struct Derived *r = func_00323C10(self);
    self->vtbl = D_00674090;
    return r;
}
