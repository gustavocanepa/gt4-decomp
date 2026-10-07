struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_0028BC78(struct Derived *self);
extern "C" char D_00663900[];
extern "C" struct Derived *func_00210768(struct Derived *self)
{
    struct Derived *r = func_0028BC78(self);
    self->vtbl = D_00663900;
    return r;
}
