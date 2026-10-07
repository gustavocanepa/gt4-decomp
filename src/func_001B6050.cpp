struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0030A678(struct Derived *self);
extern "C" char D_0065F0F8[];
extern "C" struct Derived *func_001B6050(struct Derived *self)
{
    struct Derived *r = func_0030A678(self);
    self->vtbl = D_0065F0F8;
    return r;
}
