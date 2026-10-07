struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_003A34E8(struct Derived *self);
extern "C" char D_0067E758[];
extern "C" struct Derived *func_005F7C50(struct Derived *self)
{
    struct Derived *r = func_003A34E8(self);
    self->vtbl = D_0067E758;
    return r;
}
