struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_001B99A8(struct Derived *self);
extern "C" char D_0065A2B0[];
extern "C" struct Derived *func_001BA528(struct Derived *self)
{
    struct Derived *r = func_001B99A8(self);
    self->vtbl = D_0065A2B0;
    return r;
}
