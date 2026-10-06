struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0028BC78(struct Derived *self);
extern "C" char D_0065A2B0[];
extern "C" struct Derived *func_0021B628(struct Derived *self)
{
    struct Derived *r = func_0028BC78(self);
    self->vtbl = D_0065A2B0;
    return r;
}
