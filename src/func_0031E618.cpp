struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_00328420(struct Derived *self);
extern "C" char D_00675878[];
extern "C" struct Derived *func_0031E618(struct Derived *self)
{
    struct Derived *r = func_00328420(self);
    self->vtbl = D_00675878;
    return r;
}
