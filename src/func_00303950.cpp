struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_00323C10(struct Derived *self);
extern "C" char D_006749C8[];
extern "C" struct Derived *func_00303950(struct Derived *self)
{
    struct Derived *r = func_00323C10(self);
    self->vtbl = D_006749C8;
    return r;
}
