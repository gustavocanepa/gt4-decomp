struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0028E8E8(struct Derived *self);
extern "C" char D_00667888[];
extern "C" struct Derived *func_0026BB40(struct Derived *self)
{
    struct Derived *r = func_0028E8E8(self);
    self->vtbl = D_00667888;
    return r;
}
