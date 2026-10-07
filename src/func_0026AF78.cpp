struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0026A348(struct Derived *self);
extern "C" char D_00667558[];
extern "C" struct Derived *func_0026AF78(struct Derived *self)
{
    struct Derived *r = func_0026A348(self);
    self->vtbl = D_00667558;
    return r;
}
