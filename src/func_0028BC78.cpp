struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_00328420(struct Derived *self);
extern "C" char D_0066A9F0[];
extern "C" struct Derived *func_0028BC78(struct Derived *self)
{
    struct Derived *r = func_00328420(self);
    self->vtbl = D_0066A9F0;
    return r;
}
