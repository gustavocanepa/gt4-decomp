struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0028BC78(struct Derived *self);
extern "C" char D_006640E8[];
extern "C" struct Derived *func_0021B628(struct Derived *self)
{
    struct Derived *r = func_0028BC78(self);
    self->vtbl = D_006640E8;
    return r;
}
