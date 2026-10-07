struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_00255298(struct Derived *self);
extern "C" char D_0065FFA8[];
extern "C" struct Derived *func_001BD0D0(struct Derived *self)
{
    struct Derived *r = func_00255298(self);
    self->vtbl = D_0065FFA8;
    return r;
}
