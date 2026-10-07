struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_001B8B68(struct Derived *self);
extern "C" char D_006602B0[];
extern "C" struct Derived *func_001BE0B8(struct Derived *self)
{
    struct Derived *r = func_001B8B68(self);
    self->vtbl = D_006602B0;
    return r;
}
