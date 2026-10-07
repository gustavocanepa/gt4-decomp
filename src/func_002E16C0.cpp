struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0030A678(struct Derived *self);
extern "C" char D_006720E0[];
extern "C" struct Derived *func_002E16C0(struct Derived *self)
{
    struct Derived *r = func_0030A678(self);
    self->vtbl = D_006720E0;
    return r;
}
