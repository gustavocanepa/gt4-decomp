struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0028E8E8(struct Derived *self);
extern "C" char D_0066E148[];
extern "C" struct Derived *func_005E7E80(struct Derived *self)
{
    struct Derived *r = func_0028E8E8(self);
    self->vtbl = D_0066E148;
    return r;
}
