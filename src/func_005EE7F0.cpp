struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_00328420(struct Derived *self);
extern "C" char D_00674120[];
extern "C" struct Derived *func_005EE7F0(struct Derived *self)
{
    struct Derived *r = func_00328420(self);
    self->vtbl = D_00674120;
    return r;
}
